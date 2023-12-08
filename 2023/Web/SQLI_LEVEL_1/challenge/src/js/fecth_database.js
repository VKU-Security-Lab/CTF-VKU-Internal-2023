document.addEventListener('DOMContentLoaded', function() {
    // Gọi hàm để thực hiện POST request khi trang đã tải hoàn toàn
    // sendPostRequest();
    document.getElementById('btn_login').addEventListener('click', sendPostRequest);
});

function sendPostRequest() {
    // Địa chỉ của file server xử lý yêu cầu POST (trong trường hợp này là rev.php)
    const url = '/check_login.php';

    const username = document.getElementById('username').value;
    const password = document.getElementById('password').value;

    // Dữ liệu cần gửi đi (trong trường hợp này là biến username)
    const data = { 
        username: username ,
        password: password
    
    };

    // Thiết lập các tùy chọn của request
    const options = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    };

    // Sử dụng fetch để gửi yêu cầu POST
    fetch(url, options)
        .then(response => response.json())
        .then(result => {
            // In ra kết quả từ server (trong trường hợp này là biến username)
            console.log('Server response:', result);
            if(result != false){
                alert(result);
            }else{
                alert("INFORMATION FAILED");
                document.getElementById('username').value = '';
                document.getElementById('password').value = '';
                location.reload();                
            }
        })
        .catch(error => console.error('Error:', error));
}
