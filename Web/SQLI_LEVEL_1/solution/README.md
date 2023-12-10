# Solve **SQL Injection Level 1**

Để giải bài này, bạn chỉ cần đăng nhập vào được trang web. Tuy nhiên không có tài khoản và cũng không có tính năng đăng ký tài khoản.
Ở đây, sử dụng lỗi SQL Injection để có thể đăng nhập được.

Bạn có thể hình dung câu truy vấn SQL để đăng nhập là: `SELECT * FROM users WHERE username = '$_POST[username]' and password = '$_POST[password]'
`
Điền username bằng `' or 1=1 -- ` còn mật khẩu thì bạn điền gì cũng được.

![Alt text](image.png)

`Flag: VKU{VERY_very_E4s9}`
