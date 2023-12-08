<?php
$servername = getenv('MYSQL_HOSTNAME');
$username = getenv('MYSQL_USER');
$password = getenv('MYSQL_ROOT_PASSWORD');
$dbname = getenv('MYSQL_DATABASE');
try {
    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // Nhận dữ liệu từ yêu cầu POST
    $data = json_decode(file_get_contents("php://input"));
    // Lấy giá trị của biến username
    $productID = $data->productID;
    // In ra biến username
    $sql = "SELECT * FROM products WHERE productsid=$productID";

    $result = $conn->query($sql);

    if($result === false){
        throw new Exception($conn->error);
    }

    if ($result->num_rows > 0) {
        exit(json_encode($result->fetch_all(MYSQLI_ASSOC)));
    } else {
        exit(json_encode("NOT"));
    }
} catch (Exception $e) {
    echo json_encode(['error' => $e->getMessage()]);
} finally {
    // Đóng kết nối trong mọi trường hợp
    if (isset($conn)) {
        $conn->close();
    }
}
