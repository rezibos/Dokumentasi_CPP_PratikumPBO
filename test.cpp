#include <iostream>
#include <string>
#include <windows.h>
#include<vector>
using namespace std;

struct UserInput {
    string selectedOption;
    string inputText;
    bool isValid;
};

UserInput tampilkanDialogInput() {
    UserInput result = {"", "", false};
    
    string command = 
        "powershell -command \""
        "Add-Type -AssemblyName System.Windows.Forms; "
        "$form = New-Object Windows.Forms.Form; "
        "$form.Text = 'Input Data User'; "
        "$form.StartPosition = 'CenterScreen'; "
        "$form.Width = 400; "
        "$form.Height = 300; "
        "$form.FormBorderStyle = 'FixedDialog'; "
        "$form.MaximizeBox = $false; "
        
        // Label untuk ComboBox
        "$labelCombo = New-Object Windows.Forms.Label; "
        "$labelCombo.Text = 'Pilih Kategori:'; "
        "$labelCombo.Location = New-Object System.Drawing.Point(20,20); "
        "$labelCombo.Width = 120; "
        "$labelCombo.Height = 20; "
        "$form.Controls.Add($labelCombo); "
        
        // ComboBox
        "$comboBox = New-Object Windows.Forms.ComboBox; "
        "$comboBox.Location = New-Object System.Drawing.Point(20,45); "
        "$comboBox.Width = 340; "
        "$comboBox.Height = 25; "
        "$comboBox.DropDownStyle = [System.Windows.Forms.ComboBoxStyle]::DropDownList; "
        "$comboBox.Items.Add('Makanan'); "
        "$comboBox.Items.Add('Minuman'); "
        "$comboBox.Items.Add('Snack'); "
        "$comboBox.Items.Add('Dessert'); "
        "$comboBox.SelectedIndex = 0; "
        "$form.Controls.Add($comboBox); "
        
        // Label untuk TextBox
        "$labelText = New-Object Windows.Forms.Label; "
        "$labelText.Text = 'Masukkan Nama Item:'; "
        "$labelText.Location = New-Object System.Drawing.Point(20,85); "
        "$labelText.Width = 150; "
        "$labelText.Height = 20; "
        "$form.Controls.Add($labelText); "
        
        // TextBox untuk input
        "$textBox = New-Object Windows.Forms.TextBox; "
        "$textBox.Location = New-Object System.Drawing.Point(20,110); "
        "$textBox.Width = 340; "
        "$textBox.Height = 25; "
        "$textBox.Text = ''; "
        "$form.Controls.Add($textBox); "
        
        // Label untuk harga
        "$labelHarga = New-Object Windows.Forms.Label; "
        "$labelHarga.Text = 'Harga (Rp):'; "
        "$labelHarga.Location = New-Object System.Drawing.Point(20,150); "
        "$labelHarga.Width = 100; "
        "$labelHarga.Height = 20; "
        "$form.Controls.Add($labelHarga); "
        
        // TextBox untuk harga (hanya angka)
        "$textBoxHarga = New-Object Windows.Forms.TextBox; "
        "$textBoxHarga.Location = New-Object System.Drawing.Point(20,175); "
        "$textBoxHarga.Width = 340; "
        "$textBoxHarga.Height = 25; "
        "$textBoxHarga.Text = '0'; "
        "$form.Controls.Add($textBoxHarga); "
        
        // Tombol OK
        "$buttonOK = New-Object Windows.Forms.Button; "
        "$buttonOK.Text = 'OK'; "
        "$buttonOK.Location = New-Object System.Drawing.Point(200,220); "
        "$buttonOK.Width = 80; "
        "$buttonOK.Height = 30; "
        "$buttonOK.DialogResult = [System.Windows.Forms.DialogResult]::OK; "
        "$form.Controls.Add($buttonOK); "
        
        // Tombol Cancel
        "$buttonCancel = New-Object Windows.Forms.Button; "
        "$buttonCancel.Text = 'Cancel'; "
        "$buttonCancel.Location = New-Object System.Drawing.Point(290,220); "
        "$buttonCancel.Width = 80; "
        "$buttonCancel.Height = 30; "
        "$buttonCancel.DialogResult = [System.Windows.Forms.DialogResult]::Cancel; "
        "$form.Controls.Add($buttonCancel); "
        
        "$form.AcceptButton = $buttonOK; "
        "$form.CancelButton = $buttonCancel; "
        
        // Tampilkan form dan ambil hasil
        "$dialogResult = $form.ShowDialog(); "
        "if ($dialogResult -eq 'OK') { "
        "    if ($textBox.Text -ne '' -and $textBoxHarga.Text -ne '') { "
        "        Write-Output ($comboBox.SelectedItem.ToString() + '|' + $textBox.Text + '|' + $textBoxHarga.Text + '|SUCCESS'); "
        "    } else { "
        "        [System.Windows.Forms.MessageBox]::Show('Mohon isi semua field!', 'Error'); "
        "        Write-Output 'ERROR'; "
        "    } "
        "} else { "
        "    Write-Output 'CANCELLED'; "
        "}\"";
    
    // Buat file temporary untuk menangkap output
    string tempFile = "temp_output.txt";
    string fullCommand = command + " > " + tempFile;
    
    int systemResult = system(fullCommand.c_str());
    
    // Baca hasil dari file temporary
    FILE* file = fopen(tempFile.c_str(), "r");
    if (file != nullptr) {
        char buffer[1000];
        if (fgets(buffer, sizeof(buffer), file) != nullptr) {
            string output = buffer;
            // Hapus newline di akhir
            if (!output.empty() && output.back() == '\n') {
                output.pop_back();
            }
            
            if (output.find("SUCCESS") != string::npos) {
                // Parse hasil: kategori|nama|harga|SUCCESS
                size_t pos1 = output.find('|');
                size_t pos2 = output.find('|', pos1 + 1);
                size_t pos3 = output.find('|', pos2 + 1);
                
                if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos) {
                    result.selectedOption = output.substr(0, pos1);
                    result.inputText = output.substr(pos1 + 1, pos2 - pos1 - 1);
                    string harga = output.substr(pos2 + 1, pos3 - pos2 - 1);
                    result.inputText += " - Rp" + harga; // Gabungkan nama dengan harga
                    result.isValid = true;
                }
            }
        }
        fclose(file);
    }
    
    // Hapus file temporary
    remove(tempFile.c_str());
    
    return result;
}

bool tampilkanPilihanDialog(const string& judul, const string& pesan, const vector<string>& pilihan, string& hasilPilihan) {
    string items = "";
    for (size_t i = 0; i < pilihan.size(); i++) {
        items += "$comboBox.Items.Add('" + pilihan[i] + "'); ";
    }
    
    string command = 
        "powershell -command \""
        "Add-Type -AssemblyName System.Windows.Forms; "
        "$form = New-Object Windows.Forms.Form; "
        "$form.Text = '" + judul + "'; "
        "$form.StartPosition = 'CenterScreen'; "
        "$form.Width = 350; "
        "$form.Height = 200; "
        "$form.FormBorderStyle = 'FixedDialog'; "
        "$form.MaximizeBox = $false; "
        
        // Label pesan
        "$label = New-Object Windows.Forms.Label; "
        "$label.Text = '" + pesan + "'; "
        "$label.Location = New-Object System.Drawing.Point(20,20); "
        "$label.Width = 300; "
        "$label.Height = 40; "
        "$form.Controls.Add($label); "
        
        // ComboBox
        "$comboBox = New-Object Windows.Forms.ComboBox; "
        "$comboBox.Location = New-Object System.Drawing.Point(20,70); "
        "$comboBox.Width = 300; "
        "$comboBox.DropDownStyle = [System.Windows.Forms.ComboBoxStyle]::DropDownList; "
        + items +
        "$comboBox.SelectedIndex = 0; "
        "$form.Controls.Add($comboBox); "
        
        // Tombol OK
        "$buttonOK = New-Object Windows.Forms.Button; "
        "$buttonOK.Text = 'OK'; "
        "$buttonOK.Location = New-Object System.Drawing.Point(180,120); "
        "$buttonOK.Width = 70; "
        "$buttonOK.Height = 30; "
        "$buttonOK.DialogResult = [System.Windows.Forms.DialogResult]::OK; "
        "$form.Controls.Add($buttonOK); "
        
        // Tombol Cancel
        "$buttonCancel = New-Object Windows.Forms.Button; "
        "$buttonCancel.Text = 'Cancel'; "
        "$buttonCancel.Location = New-Object System.Drawing.Point(260,120); "
        "$buttonCancel.Width = 70; "
        "$buttonCancel.Height = 30; "
        "$buttonCancel.DialogResult = [System.Windows.Forms.DialogResult]::Cancel; "
        "$form.Controls.Add($buttonCancel); "
        
        "$form.AcceptButton = $buttonOK; "
        "$form.CancelButton = $buttonCancel; "
        
        // Tampilkan dan ambil hasil
        "if ($form.ShowDialog() -eq 'OK') { "
        "    Write-Output $comboBox.SelectedItem.ToString(); "
        "} else { "
        "    Write-Output 'CANCELLED'; "
        "}\"";
    
    string tempFile = "temp_choice.txt";
    string fullCommand = command + " > " + tempFile;
    
    system(fullCommand.c_str());
    
    bool success = false;
    FILE* file = fopen(tempFile.c_str(), "r");
    if (file != nullptr) {
        char buffer[500];
        if (fgets(buffer, sizeof(buffer), file) != nullptr) {
            string output = buffer;
            if (!output.empty() && output.back() == '\n') {
                output.pop_back();
            }
            
            if (output != "CANCELLED") {
                hasilPilihan = output;
                success = true;
            }
        }
        fclose(file);
    }
    
    remove(tempFile.c_str());
    return success;
}

// Contoh penggunaan
int main() {
    cout << "=== Demo Dialog Input ===" << endl;
    
    // Test dialog input lengkap
    UserInput hasil = tampilkanDialogInput();
    
    if (hasil.isValid) {
        cout << "Kategori dipilih: " << hasil.selectedOption << endl;
        cout << "Item yang dimasukkan: " << hasil.inputText << endl;
    } else {
        cout << "Input dibatalkan atau tidak valid." << endl;
    }
    
    cout << "\n=== Demo Dialog Pilihan Sederhana ===" << endl;
    
    // Test dialog pilihan sederhana
    vector<string> pilihan = {"Dine In", "Take Away", "Delivery"};
    string hasilPilihan;
    
    if (tampilkanPilihanDialog("Metode Pesanan", "Pilih metode pesanan:", pilihan, hasilPilihan)) {
        cout << "Metode dipilih: " << hasilPilihan << endl;
    } else {
        cout << "Pilihan dibatalkan." << endl;
    }
    
    return 0;
}