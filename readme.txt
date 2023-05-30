+ MSSV và Họ tên sinh viên:
	21120297 - Phùng Lê Hoàng Ngọc
	21120307 - Trần Đình Nhật

+ Các chức năng đã làm được:
- Đọc danh sách các đối tượng hình học được lưu trong tập tin shapes.txt
- In ra màn hình danh sách các hình đã đọc
- Sắp xếp các hình đã đọc tăng dần theo diện tích và in ra màn hình theo dạng cột

- Sử dụng mẫu thiết kế design pattern:
	. Singleton
	. Factory (cho việc parse)
	. Strategy (cho việc hiển thị)
	. Nguyên tắc dependency injection

- Sử dụng con trỏ thông minh giải quyết các vấn đề về con trỏ
- Comment đầy đủ ý nghĩa các hàm trong mã nguồn (tham số, kết quả trả về)
- Có bắt các lỗi và xử lí các ngoại lệ dễ nhận ra (Không có dữ liệu, dữ liệu không đúng định dạng, dữ liệu không đúng miền giá trị)
- Ngoài các đối tượng Circle, Square, Rectangle, nhóm đã bổ sung thêm các đối tượng Triangle, Diamond và Ellipse
- Bổ sung unit test cho các lớp Circle, Square, Rectangle, Triangle, Diamond, Ellipse 
và các lớp CircleParser, SquareParser, RectangleParser, TriangleParser, DiamondParser, EllipseParser
- Tự phát sinh ra tài liệu mô tả hệ thống dưới dạng file html

+ Để chạy mã nguồn, cần lưu ý như sau:
- Lúc khởi động chương trình cần nhập tên file chứa dữ liệu (vd: shapes.txt)
- File chứa dữ liệu cần tuân theo các nguyên tắc sau đây để có thể đọc được dữ liệu:
	. Dòng đầu: chứa số lượng đối tượng hình học
	. Các dòng sau: <Tên đối tượng hình học>: <tên biến> = <giá trị>, ...

Ví dụ về 1 file shapes.txt có định dạng như sau (các dấu khoảng cách không ảnh hưởng đến việc đọc dữ liệu):
"6
Triangle: a =3, b=4, c=5
Square: a= 12
Rectangle: w = 3, h=4
Circle: r=5
Ellipse: major=4,minor=3
Diamond: p=10, q = 8"

+ Các đặc điểm đặc biệt:
- Sử dụng regex để bắt toàn bộ lỗi về dữ liệu không đúng định dạng và trả về nullptr

+ Điểm tự đánh giá: 10/10