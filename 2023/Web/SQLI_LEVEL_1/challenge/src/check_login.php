<?php
    $servername = getenv('MYSQL_HOSTNAME');
    $username = getenv('MYSQL_USER');
    $password = getenv('MYSQL_ROOT_PASSWORD');
    $dbname = getenv('MYSQL_DATABASE');

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
    }

    // Nhận dữ liệu từ yêu cầu POST
    $data = json_decode(file_get_contents("php://input"));
    // Lấy giá trị của biến username
    $username = $data->username;
    $password = $data->password;
    // In ra biến username
    $sql="SELECT * from users WHERE username='$username' AND password='$password'";

    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        exit(json_encode("Congratulation, here is your flag: VKU{VERY_very_E4s9}"));
    }
    else {
        exit(json_encode(false));
    }
    $conn->close();
?>