# Tetris

Game Tetris c++ sử dụng thư viện graphics.h
Nguồn tham khảo code : https://www.youtube.com/watch?v=-s7QhkHPuTE&t=126s

Link tải code tham khảo về : https://www.dropbox.com/s/jgv6ueivxkapvth/Tetris.zip?dl=0

Các tính năng mới:
* Màu sắc khác nhau cho từng khối
* Tốc độ rơi tăng lên 10% sau mỗi ván (level)
* Nút chơi lại (restart)
* Sửa lại hệ thống tính điểm:
  - Mỗi khối có cách tính điểm số riêng, điểm chỉ được cộng lên sau khi khối được đặt xuống:
     (+)   Khối T: +5 điểm
     (+)   Khối L ngược và khối L xuôi: +15 điểm
     (+)   Khối bậc thang ngược và khối bậc thang xuôi: +25 điểm
     (+)   Khối vuông: +20 điểm
     (+)   Khối thẳng dài: +10 điểm
  - Một hàng ngang được lấp đầy: +100 điểm
  - Điểm Combo:
     (+)   Nếu có n hàng ngang liên tiếp, thì hàng ngang thứ 2 sẽ cộng vào 200 điểm, hàng ngang thứ 3 sẽ cộng vào 300 điểm, vv... (nhiều nhất là +1000 điểm)
     (+)   Nếu đang có combo và lần đặt khối tiếp theo lại tạo hàng ngang thì combo vẫn được cộng lên tiếp
     (+)   Nếu đang có combo và lần đặt khối tiếp theo không tạo hàng ngang thì combo sẽ bị mất
     (+)   Có phần hiển thị combo ở trên màn hình
  - Sau 1000 điểm thì sẽ lên một level

* Lưu trữ lại và hiển thị điểm số cao nhất sau một lần chơi
  
* Bom:
     (+)   Ban đầu sẽ có 2 viên
     (+)   Mỗi lần dùng sẽ xóa đi 4 hàng đáy và kéo các hàng phía trên xuống
     (+)   Nếu không có gì ở 4 hàng cuối thì bom vẫn được dùng nhưng sẽ không làm gì cả
     (+)   được tặng thêm một viên nếu lên level 2, 4, 6, 8, ...
     (+)   Sử dụng bom không tăng điểm số
* Template: bắt đầu game với các khối được đặt sẵn theo các hình dạng nhất định (có 3 mẫu)


Điều khiển:
     (+)   Mũi tên trái : di chuyển sang bên trái
     (+)   Mũi tên phải : di chuyển sang bên phải
     (+)   Mũi tên xuống : đặt khối xuống dưới
     (+)   Nút '0' : Dừng game lại (pause)
     (+)   Nút 'r' : Chơi lại từ đầu
     (+)   Nút 'h', 's', 'c':  Chơi lại từ đầu với một template
     (+)   Nút '1' : Chơi lại game (sau khi thua)
     (+)   Nút 'x' : thoát game


     
     
     
     
