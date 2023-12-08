document.addEventListener('DOMContentLoaded', function () {
    // Gọi hàm để thực hiện POST request khi trang đã tải hoàn toàn
    // sendPostRequest();
    document.getElementById('add_from_table').addEventListener('click', addUser);
    document.getElementById('delete_from_table').addEventListener('click', removeUser);
    autoUpdate();
});
// const result_search = document.getElementById('result_search');
// console.log(result_search)
function autoUpdate() {
    const url = '/admin.php';
    const dataClear = {
        requestMethod: "getAllUsers"
    };
    const data = btoa(JSON.stringify(dataClear));

    const options = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ data: data }) // Wrap the data in an object if needed
    };
    fetch(url, options)
        .then(response => response.json())
        .then(result => {
            output = '';
            // In ra kết quả từ server (trong trường hợp này là biến username)
            // console.log('Server response:', result);
            for (let i in result) {
                output += `
            <tr>
                <td>${result[i].username}</td>
                <td>${result[i].password}</td>
            </tr>
            `;
            }
            document.getElementById('tbodyUsers').innerHTML = output;
            reUITable();
        })
        .catch(error => console.error('Error:', error));
}
function reUITable() {
    $(document).ready(function () {
        var tableRows = $('table tbody tr');
        var pageSize = 10;
        var currentPage = 1;
        var totalPages = Math.ceil(tableRows.length / pageSize);

        function displayRows() {
            tableRows.hide();
            var startIndex = (currentPage - 1) * pageSize;
            var endIndex = startIndex + pageSize;
            tableRows.slice(startIndex, endIndex).show();
        }

        function updateButtonState() {
            if (currentPage === totalPages) {
                $('#nextButton').prop('disabled', true);
            } else {
                $('#nextButton').prop('disabled', false);
            }

            if (currentPage === 1) {
                $('#prevButton').prop('disabled', true);
            } else {
                $('#prevButton').prop('disabled', false);
            }
        }

        displayRows();
        updateButtonState();

        $('#nextButton').on('click', function () {
            if (currentPage < totalPages) {
                currentPage++;
                displayRows();
                updateButtonState();
            }
        });

        $('#prevButton').on('click', function () {
            if (currentPage > 1) {
                currentPage--;
                displayRows();
                updateButtonState();
            }
        });
    });
}
function addUser() {
    const url = '/admin.php';

    const username_add_sql = document.getElementById('username_add_sql').value;
    const password_add_sql = document.getElementById('password_add_sql').value;
    const dataClear = {
        username_add_sql: username_add_sql,
        password_add_sql: password_add_sql,
        requestMethod: "addUser",
        // productID: productID
    };

    const data = btoa(JSON.stringify(dataClear));

    const options = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ data: data }) // Wrap the data in an object if needed
    };
    fetch(url, options)
        .then(response => response.json())
        .then(result => {
            // In ra kết quả từ server (trong trường hợp này là biến username)
            console.log('Server response:', result);
            if (result == true) {
                // alert(result);
                document.getElementById('username_add_sql').value = '';
                document.getElementById('password_add_sql').value = '';
            } else {
                alert("ADD FAILED");
            }
        })
        .catch(error => console.error('Error:', error));
    $('#addUserLableModal').modal('hide');
    autoUpdate();
    location.reload();
}
function removeUser() {
    const url = '/admin.php';
    const username_remove_sql = document.getElementById('username_remove_sql').value;
    
    // Create an object with the data to be sent
    const dataClear = {
        username_remove_sql: username_remove_sql,
        requestMethod: "removeUser",
    };

    // Convert the object to a JSON string and then encode to base64
    const data = btoa(JSON.stringify(dataClear));

    const options = {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ data: data }) // Wrap the data in an object if needed
    };

    // Make the fetch call
    fetch(url, options)
        .then(response => response.json())
        .then(result => {
            // Handle the response here
            // console.log(result);
            // You can do something with the result if needed
        })
        .catch(error => console.error('Error:', error));

    // Clear the input and hide the modal
    document.getElementById('username_remove_sql').value = '';
    location.reload();
    $('#removeUserLableModal').modal('hide');
    autoUpdate();
    // You may want to call autoUpdate here or wherever appropriate
    // autoUpdate();
}