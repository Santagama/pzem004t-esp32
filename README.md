# pzem004t-esp32
 Real-time Power Monitoring with ESP32 & PZEM004Tv3.0
Sistem monitoring konsumsi listrik berbasis ESP32 dan sensor PZEM004Tv3.0, yang mengirimkan data tegangan, arus, daya, dan energi ke server PHP dan menampilkannya secara real-time di halaman web tanpa refresh.

📦 Fitur Utama
📶 ESP32 membaca data listrik dari PZEM004Tv3.0 melalui serial (UART).
🌐 Data dikirim ke server PHP menggunakan HTTP (WiFi).
🖥️ Halaman web menampilkan nilai tegangan (V), arus (A), daya (W), dan energi (Wh) secara real-time menggunakan AJAX + JavaScript.
🔁 Update data otomatis tiap 1 detik tanpa perlu refresh.

🚀 Cara Kerja Singkat
ESP32 membaca data dari PZEM004Tv3.0.
Mengirim data ke receive.php via HTTP GET.
Server menyimpan dan menampilkan data di halaman web.
Halaman index.php mengambil data terbaru setiap detik via AJAX dan menampilkannya secara langsung.

📡 Kebutuhan
ESP32 board
Sensor PZEM004Tv3.0
Kabel jumper (TX-RX)
WiFi / hotspot aktif
Server lokal (XAMPP/Laragon) atau hosting

✨ Requirements
Arduino IDE Setup
✅ Board Manager
Pastikan kamu sudah install:
esp32, by Espressif Systems
Arduino ESP32 Boards, by Arduino
✅ Library Manager
Install library ini melalui Tools > Manage Libraries:
PZEM004Tv30, by Jakub Mandula
