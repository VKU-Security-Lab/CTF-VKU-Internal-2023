document.addEventListener('DOMContentLoaded', function () {
    // Gọi hàm để thực hiện POST request khi trang đã tải hoàn toàn
    // sendPostRequest();
    document.getElementById('btn_search_product').addEventListener('click', sendProductID);
});
// const result_search = document.getElementById('result_search');
// console.log(result_search)
function sendProductID() {
    const url = '/ajax.php';
    const productID = document.getElementById('productID').value;
    const result_search = document.getElementById('result_search')
    result_search.innerHTML = ``
    const data = {
        productID: productID
    };
    const options = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    };
    // ...

    fetch(url, options)
        .then(response => {
            if (!response.ok) {
                throw new Error(`HTTP error! Status: ${response.status}`);
            }
            return response.json();
        })
        .then(result => {
            // Xử lý dữ liệu thành công
            console.log('Server response:', result);

            // Kiểm tra xem có lỗi từ server không
            if (result.error) {
                throw new Error(result.error);
            }

            // Xử lý dữ liệu khác ở đây
            let output = '';
            for (let i in result) {
                output += `
                <tr>
                    <td>${result[i].productsid}</td>
                    <td><img src="${result[i].urlProduct}" alt="${result[i].urlProduct}" width="500" height="600"></td>
                </tr>
            `;
            }
            result_search.innerHTML = output;
        })
        .catch(error => {
            // Xử lý lỗi
            console.error('Error:', error.message);
            // Hiển thị thông báo lỗi cho người dùng, ví dụ:
            result_search.innerHTML = `${error.message}`
        });

    // fetch(url, options)
    //     .then(response => response.json())
    //     .then(result => {
    //         // In ra kết quả từ server (trong trường hợp này là biến username)
    //         console.log('Server response:', result);
    //         let output = ''
    //         for(let i in result){
    //             output += `
    //                 <tr>
    //                     <td>${result[i].urlProduct}</td>
    //                     <td><img src="${result[i].urlProduct}" alt="${result[i].urlProduct}" width="500" height="600"></td>
    //                 </tr>
    //             `;
    //         }
    //         result_search.innerHTML = output
    //     })
    //     .catch(error => console.error('Error:', error));

}
// function sendPostRequest() {
//     // Địa chỉ của file server xử lý yêu cầu POST (trong trường hợp này là rev.php)
//     const url = '/check_login.php';

//     const username = document.getElementById('username').value;
//     const password = document.getElementById('password').value;

//     // Dữ liệu cần gửi đi (trong trường hợp này là biến username)


//     // Thiết lập các tùy chọn của request
//     const options = {
//         method: 'POST',
//         headers: {
//             'Content-Type': 'application/json'
//         },
//         body: JSON.stringify(data)
//     };

//     // Sử dụng fetch để gửi yêu cầu POST
//     fetch(url, options)
//         .then(response => response.json())
//         .then(result => {
//             // In ra kết quả từ server (trong trường hợp này là biến username)
//             console.log('Server response:', result);
//             if(result != false){
//                 alert(result);
//             }else{
//                 alert("INFORMATION FAILED");
//                 document.getElementById('username').value = '';
//                 document.getElementById('password').value = '';
//                 location.reload();                
//             }
//         })
//         .catch(error => console.error('Error:', error));
// }
