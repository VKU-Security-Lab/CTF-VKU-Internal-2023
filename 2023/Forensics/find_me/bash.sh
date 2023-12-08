#!/bin/bash

# Tạo thư mục để chứa các file
mkdir -p generated_files

# Di chuyển vào thư mục mới tạo
cd generated_files

# Số lượng file cần tạo
total_files=10000

# Tạo 10,000 file
for ((i=1; i<=$total_files; i++)); do
  # Tạo tên file
  filename="file-${i}.txt"
  
  # Tạo nội dung ngẫu nhiên 32 ký tự
  random_content=$(cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 32 | head -n 1)
  
  # Ghi nội dung vào file
  echo "$random_content" > "$filename"
done

echo "Đã tạo $total_files file trong thư mục generated_files."
