<?php
date_default_timezone_set('Asia/Jakarta'); // Atur zona waktu sesuai kebutuhan

if (isset($_GET['voltage']) && isset($_GET['current']) && isset($_GET['power']) && isset($_GET['energy'])) {
    $data = array(
        "voltage" => floatval($_GET['voltage']),
        "current" => floatval($_GET['current']),
        "power"   => floatval($_GET['power']),
        "energy"  => floatval($_GET['energy']),
        "timestamp" => date("Y-m-d H:i:s")
    );

    $json = json_encode($data, JSON_PRETTY_PRINT);
    file_put_contents("data.json", $json);

    echo "Data received and saved.";
} else {
    echo "Invalid or incomplete data.";
}
?>