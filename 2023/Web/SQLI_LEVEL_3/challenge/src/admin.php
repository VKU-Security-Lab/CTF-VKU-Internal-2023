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
// $data = json_decode(file_get_contents("php://input"));
// Lấy giá trị của biến username
// $productID = $data->productID;
$dataJson = file_get_contents("php://input");
$dataDecode = json_decode($dataJson);
$database64 = $dataDecode->data;
$dataJson1 = base64_decode($database64);
$data = json_decode($dataJson1);

$requestMethod = $data->requestMethod;

if ($requestMethod === "addUser") {
    $username = $data->username_add_sql;
    $password = $data->password_add_sql;

    $stmt = $conn->prepare("INSERT INTO users(username,password) VALUES (?,?)");
    $stmt->bind_param("ss", $username, $password);
    $stmt->execute();
    $stmt->close();

    echo json_encode(true);

} elseif ($requestMethod === "getAllUsers") {
    $sql = "SELECT * FROM users";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        // Fetch all rows as an associative array
        $data = $result->fetch_all(MYSQLI_ASSOC);
        // Convert the data array to JSON
        $json = json_encode($data);
        // Output the JSON
        echo $json;
    } else {
        // echo json_encode([["username" => "EMPTY", "password" => "EMPTY"]]);
        echo json_encode("EMPTY");
    }
} elseif ($requestMethod === "removeUser") {

    $username_remove_sql = $data->username_remove_sql;
    $sql = "DELETE FROM users WHERE username='$username_remove_sql'";
    // echo json_encode($sql);
    $result = $conn->query($sql);
    // echo json_encode("YES");
} else {
    // echo json_encode("NOT");
}
$conn->close();
// // In ra biến username
// $sql = "SELECT * FROM products WHERE productsid=$productID";

// $result = $conn->query($sql);

// if ($result === false) {
//     throw new Exception($conn->error);
// }

// if ($result->num_rows > 0) {
//     exit(json_encode($result->fetch_all(MYSQLI_ASSOC)));
// } else {
//     exit(json_encode("NOT"));
// }
