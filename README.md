Bạn có thể tham khảo mục README mẫu dưới đây, mình viết ngắn gọn và rõ ràng để phù hợp cho các lab:

---

# README

## Cách chạy các lab

1. Mỗi **lab** đã được cài sẵn hàm thực thi trong code.
2. Trong vòng lặp `while (1)` của file `main.c`, các hàm gọi lab được **comment** sẵn để tránh xung đột.
3. Để chạy một lab cụ thể, hãy:

   * **Uncomment** (xóa `//`) trước hàm của lab cần chạy.
   * Đảm bảo chỉ giữ **một hàm lab** được bật tại một thời điểm để tránh lỗi.
4. Biên dịch và nạp chương trình vào board để kiểm tra kết quả.

Ví dụ:

```c
while (1)
{
    // ex1();
    ex2();   // ← chạy Lab 2
    // ex3();
}
```

---

