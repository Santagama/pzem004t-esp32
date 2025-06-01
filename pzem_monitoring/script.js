function fetchData() {
  fetch('data.php')
    .then(res => res.json())
    .then(data => {
      if (!data.error) {
        document.getElementById('voltage').textContent = data.voltage.toFixed(2);
        document.getElementById('current').textContent = data.current.toFixed(2);
        document.getElementById('power').textContent = data.power.toFixed(2);
        document.getElementById('energy').textContent = data.energy.toFixed(2);
        document.getElementById('timestamp').textContent = data.timestamp;
      }
    })
    .catch(err => {
      console.error('Gagal ambil data:', err);
    });
}

// Fetch data tiap 2 detik
setInterval(fetchData, 2000);
fetchData(); // Panggil sekali saat pertama buka