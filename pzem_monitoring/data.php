<?php
header('Content-Type: application/json');

if (file_exists("data.json")) {
    echo file_get_contents("data.json");
} else {
    echo json_encode(["error" => "Belum ada data"]);
}
?>