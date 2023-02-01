Cấu trúc markdown cơ bản
	# h1
	# h2
	...
	*in đậm*
	**bôi đậm*
	***in nghiêng và bôi đậm***
	`thêm code`
	[title](link//anh)
	gạch đầu dòng:
		*
		*
		*
		hoặc
		1.
		2.
		3.
	gạch kẻ ***
	highlight text >
	\
	{@youtube: Youtube ID or url}
SQL: structured Query Language: ngôn ngữ truy vấn cấu trúc
Các vấn đề cơ bản
	Khai báo dữ liệu:
		SELECT * FROM tableName: đọc tất cả dữ liệu (\*) của tableName và hiển thị
	Trường và bản ghi:
		Trường(fill) là tên các cột, các đại diện
		Bản ghi(record) là tên các dữ liệu cụ thể dựa vào form Class
		ví dụ
			có 4 trường: actor_id, first_name, last_name, last_update và 5 bản ghi
		![Trường và bản ghi](./image/recordAndClass.png)
	Cách comment:
		-- với comment đơn dòng
		/* với comment đa dòng\*/
	Các kiểu dữ liệu:
		Text: được sử dụng cho các chuỗi giá trị, như là tên hay mô tả sản phẩm
			TEXT: không giới hạn về độ dài
			VARCHAR(n): không giới hạn về độ dài, hoặc nhỏ hơn hoặc bằng n, nếu nhiều hơn n thì lỗi, n mặc định vô hạn
			CHAR(n): giới hạn về độ dài, hoạc nhỏ hơn hoặc bằng n, nếu ít hơn n thì khoảng trắng được thêm vào, n mặc định là 1
		Numeric: được sử dụng cho các giá trị số, như số lượng hay số đo
			Số nguyên:	
				SMALLINT: 2 byte, có giới hạn -32,768 -> 32,767
				INTEGER: 4 byte, có giới hạn -2,147,483,648 -> 2,147,483,647
				SERIAL: tự đạnh đánh các giá trị nguyên tăng dần
			Số thực
				FLOAT(n): 8 byte, có độ chính xác ít nhất là n
				REAL hoặc FLOAT8: 4 byte
				NUMERIC hoặc DECIMAL(p, s): *p* giới hạn chữ số nguyên trừ *s* thập phân
		Temporal: được sử dụng cho các giá trị thời gian
			DATE: ngày tháng năm
			TIME: thời gian trong ngày
			TIMESTAMP: ngày tháng năm và thời gian trong ngày, DATE + TIME
			TIMESTAMPTZ: dấu thời gian với múi giờ
			INTERVAL: khoảng thời gian
			TIMESTAMPTZ: là phần mở rộng
			CURRENT_DATE: ngày hiện tại
		Boolean: Được sử dụng cho các giá trị chỉ mang trạng thái, đúng hay sai
			Có thể dùng tự BOOLEAN hoặc BOOL
			Mang 3 giá trị: true, false, null
			Đa số đều mặc định là true
	Cách phép toán logic:
		AND: và
		OR: hoặc
		||: nối ví dụ 'QuanLe' = 'Quan' || 'Le'
		IS: là ví dụ IS NULL (là null), IS PRIMARY KEY (là khóa chính)
		<>: Khác
		...
		LENGTH(columnName): độ dài bất kì dòng của columnName
Khởi tạo bảng
	Tạo bảng: 
		CREATE TABLE tableName(
			columnName dataType constraint,
			columnName dataType constraint
		);
		constraint: có thể là lệnh DEFAULT
			ví dụ:
				salary DECIMAL(7,2) DEFAULT 0.03; 
				salary NUMERIC(7, 2) DEFAULT 0.03;			
		thêm từ khóa PRIMARY KEY: Để đặt khóa
			id SERIAL PRIMARY KEY
	Thêm dữ liệu vào bảng:
		INSERT INTO employees(emp_id, emp_name, hire_date, salary, com)
		VALUES ('SE20001','Harry','2017-01-01',2000,0.03);
		INSERT INTO employees(emp_id, emp_name, hire_date, salary, com)
		VALUES ('SE20002', 'Hermione', '2018-01-01', 2000.55, 0.04);
		INSERT INTO tableName(columnName1, columnName2, columnName3,...) VALUES(variable1, variable2, variable3,...);
	Thêm tắt dữ liệu nhanh hơn:
		INSERT INTO tableName(columnName1, columnName2, columnName3,...) VALUES(variable1, variable2, variable3,...), (variable1, variable2, variable3,...);
		>(columnName1, columnName2, columnName3,...) có thể bỏ, tự gán mặc định là toàn bộ
	Sao chép dữ liệu:
		INSERT INTO tableName(columnName1, columnName2, columnName3,...) SELECT columnName1, columnName2, columnName3,... FROM tableNameOriginal WHERE conditon;
		>(columnName1, columnName2, columnName3,...) có thể bỏ, tự gán mặc định là toàn bộ
			INSERT INTO tableName(columnName1, columnName2,...) VALUES (SELECT columnName1, columnName2 FROM tableName)
	Thêm cột dữ liệu:
		ALTER TABLE tableName 
		ADD COLUMN newColumnName1 variableOfnewColumnName1 constraint DEFAULT valueDefault1,	
		ADD COLUMN newColumnName2 variableOfnewColumnName2 constraint DEFAULT valueDefault2,
		...
		constraintDefault
	DEFAULT:
		Mặc định giá trị khi giá trị nhập vào là null
			đối với SERIAL có thể nhập DEFAULT thì giá trị tự sinh ra
			INSERT INTO tableName(id, name) VALUES(DEFAULT, "name");
	Thay đổi kiểu dữ liệu của cột:
		ALTER TABLE tableName ALTER COLUMN columnName TYPE variable;
		ví dụ: ALTER TABLE employees ALTER COLUMN emp_id TYPE VARCHAR(7);
	Thay đổi tên cột:
		ALTER TABLE columnName RENAME COLUMN oldName to newName
		ví dụ:
			ALTER TABLE order_details RENAME COLUMN unit_price to old_price;
Các ràng buộc
	Dữ liệu đầu vào nên được ràng buộc để thống nhất về ngữ nghĩa, nội dung,...
	Có 3 cách ràng buộc:
		Ràng buộc thuộc tính, ví dụ kiểu dữ liệu trên cột
		Các ràng buộc khóa, ví dụ các khóa chính
		Các ràng buộc tham chiếu, được thi hành thông qua các khóa ngoại
	Thêm ràng buộc(constraint) vào bảng đã có sẵn:
		ALTER TABLE tableName ADD CONSTRAINT constraintName constraint;
	Các loại ràng buộc:
		NOT NULL:
			bắt buộc dữ liệu phải được nhập vào
			CREATE TABLE tableName(
				columnName1 variable1 NOT NULL,
				columnName2 variable2 NOT NULL,
				...				
			);
			Thêm ràng buộc NOT NULL cho cột đã tồn tại:
				ALTER TABLE tableName ALTER COLUMN columnName SET NOT NULL
		UNIQUE:
			dữ liệu mỗi hàng của thuộc tính là duy nhất trong cột đó
			CREATE TABLE tableName(
				columnName1 variable1 UNIQUE,
				columnName2 variable2 UNIQUE,
				...				
			);
			Thêm ràng buộc UNIQUE cho cột đã tồn tại:
				ALTER TABLE tableName ADD CONSTRAINT constraintName constraint UNIQUE(columnName);
		CHECK:
			Kiểm tra dữ liệu đầu vào là hợp điều kiện
			CREATE TABLE tableName(
				columnName1 variable1 CHECK(constraint),
				columnName2 variable2 CHECK(constraint),
				...				
			);
			Thêm CHECK cho cột đã tồn tại:
				ALTER TABLE tableName 
				ADD CONSTRAINT nameConstraint1 CHECK (constraint1),
				ADD CONSTRAINT nameConstraint2 CHECK (constraint2),
				...;
			Xóa các CHECK:
				ALTER TABLE tableName 
				DROP CONSTRAINT nameConstraint,
				DROP CONSTRAINT nameConstraint,
				...;
	Khóa 
		SuperKey: là tổ hợp duy nhất không trùng lặp dữ liệu
		Key: 
			Là superKey tổ hợp duy nhất không trùng lặp dữ liệu
			Không NULL
			Bất biến theo thời gian
			CREATE TABLE tableName(
					columnName1 variable1 PRIMARY KEY,
					columnName2 variable2,
					...				
				);
			hoặc thêm sau tương tự như UNIUE:
				ALTER TABLE tableName ADD CONSTRAINT constraintName PRIMARY KEY(columnName);
		ForeignerKey:
			Là liên kết, đường dẫn đến một bảng dữ liệu khác
			Không nhất thiết phải là khóa chính của báng dữ liệu được trỏ đến
			Được tồn tại dưới dạng giá trị(hiển nhiên)	
			Có thể mang giá trị NULL
			*
			CREATE TABLE1 tableName1(
				columnName1 variable1 PRIMARY KEY,
				columnName2 variable2,
				...	
				FOREIGN KEY (columnName2,...) REFERENCES tableName2(columnName2,...)			
			);
			*
			CREATE TABLE2 tableName2(
				columnName1 variable1 PRIMARY KEY,
				columnName2 variable2 REFERENCES tableName3(columnName2),
				...				
			);
			*
			CREATE TABLE2 tableName2(
				columnName1 variable1 PRIMARY KEY,
				columnName2 variable2,
				...	
				FOREIGN KEY (columnName2) REFERENCES tableName4(columnName2)			
			);	
Sửa đổi dữ liệu
	Cập nhật dữ liệu có điều kiện
		UPDATE tableName
		SET columnName1 = variable1, columnName2 = variable2,... 
		WHERE constraint;
		Ví dụ: 
			UPDATE reservedNicknames
			SET nickname = 'rename - ' || nickname, id = 'rename - ' || id
			WHERE LENGTH(nickname) <> 8;
	Cập nhật dữ liệu không điều kiện
		UPDATE tableName
		SET columnName1 = variable1, columnName2 = variable2,...;
		Ví dụ:
			UPDATE employees
			SET salary = salary * 1.1;
	Cập nhật dữ liệu từ dữ liệu có sẵn
		UPDATE tableName1
		SET columnNameChanged = columnNameCopied --hoặc columnNameChanged = columnName2columnNameCopied
		FROM columnName2
		WHERE constraint1 AND constraint2 OR constraint3...;
		Ví dụ:
			UPDATE affiliations
			SET professor_id = id
			FROM professors
			WHERE affiliations.first_name = professors.first_name
			AND affiliations.last_name = professors.last_name;
	Xóa cột:
		> ALTER TABLE [IF EXITSTS] tableName DROP COLUMN columnName [CASCADE|RESTRICT];
		ALTER TABLE tableName 
		DROP COLUMN columnName1,
		DROP COLUMN columnName2,
		...;
		Có thể thêm các tùy chọn:
			CASCADE: để xóa các đối tượng liên quan
				ALTER TABLE tableName DROP COLUMN columnName CASCADE;
			IF EXITSTS: giả định bảng không tồn tại thì chỉ thông báo, chứ không báo lỗi
				ALTER TABLE tableName DROP COLUMN IF EXITSTS columnName;
			RESTRICT: Không xóa các đối tượng có ít nhất các đối tượng liên quan, trái với CASCADE, mặc định
				ALTER TABLE tableName DROP COLUMN columnName RESTRICT;
	Xóa dòng dữ liệu:
		> DELETE FROM tableName WHERE constraint;
			DELETE FROM movies WHERE actor = 4;
	Xóa bảng: 
		> TRUNCATE TABLE tableName;
			Không cần quét qua dữ liệu mà trực tiếp xóa, bỏ qua các bảng có tham chiếu khóa ngoại
			TRUNCATE TABLE tableName1, tableName2,...
			Có thể thêm tùy chọn CASCADE để xóa các bàng có ràng buộc
			TRUNCATE TABLE tableName1 CASCADE;
Chuẩn hóa cơ sở dữ liệu (Data normalization)
![Data normalization](./image/dataNormalizationExamples.png)
	Dư thừa dữ liệu(Data Redundancy): Các cột branch, hod, office_tel lặp đi lặp lại dữ liệu
	Chèn dị thường(Insertion anomalies): Giả sử có 100 sinh viên, thì dữ liệu lại được lặp đi lặp lại 100 lần
	Cập nhật dị thường(Updation anomaly): Xuất phát từ chèn dị thường(Insertion anomalies), các dữ liệu khi được cập nhật mới (Ví dụ thay đổi tên giáo sư - hod) không đầy đủ, có thể thiếu sót
	Xóa dị thường(Deletion anomaly): Các dữ liệu không liên quan nằm chung bảng, khi xóa dữ liệu với mục đích A, dẫn đến mất dữ liệu không liên quan
	> Giảm sự trung lặp + nhất quán mục đích + Tạo điều kiện để ánh xạ dễ kiểm soát
	1NF(1st normal Form): Các dữ liệu phải là nguyên tố, không thể chia nhỏ hơn
		quanLe.Course{Python, SQL, JS} -> quanLe.Course{Python}, quanLe.Course{SQL}, quanLe.Course{JS},
	2NF(2nd normal Form): Các cột không khóa phải phụ thuộc hoàn toàn vào khóa chính của bảng > Các dữ liệu liên quan đến nhau
		(id, name, province, villagesOfProvince) -> (id, name, idProvince) + (idProvince, province, villagesOfProvince)
	3NF(3rd normal Form): Các dữ liệu trong cùng một bảng, cột này không thể suy ra từ cột khác, hoặc cụm cột các 
		(id, name, provinceCode, state) -> (id, name, provinceCode) + (provinceCode, state)
Truy vấn dữ liệu
	Lọc dữ liệu:
		> SELECT columnName1, columnName2,... FROM tableName;
		SELECT firstName, lastName FROM students;
		Sử dụng acterisk "\*" để chọn tất cả:
			SELECT * FROM students;
	Sử dụng tên thay thế:
		> SELECT columnName [AS] nameSubstituteOfCulumn FROM tableName AS nameSubstituteOfTable
		SELECT postal_code ||', '||address||', '||district||', '||city AS address FROM address;
		> SELECT longTableNameSubstitute.columnName FROM longTableName [AS] longTableNameSubstitute
		> SELECT s.age FROM highStudentOverM80 AS s;
	Chuyển đổi kiểu dữ liệu:
		> CAST (columnName AS variableTarget);
		 SELECT CAST('100' AS INTEGER),
		 SELECT CAST('01-OCT-2015' AS DATE),
		 SELECT CAST('10.2' AS DOUBLE PRECISION),
		 SELECT CAST('true' AS BOOLEAN)
		 FROM loan;
		> columnName::variableTarget;
			SELECT '15 minute'::INTERVAL,
	 		SELECT '2 week'::INTERVAL 
	 		FROM time;
	Thực hiện phép toán
	 	> SELECT columnName1 \*|\\|+|- columnName2 FROM tableName;
	 	`SELECT a, b, a*b as c FROM multiplication`
	Làm tròn số:
		> SELECT ROUND(columnName, n) AS columnName FROM tableName;
		Với n là số chữ số sau thập phân, mặc định là tròn nguyên
		SELECT id, ROUND(point, 2) as point FROM transcript;
		SELECT ROUND(10.4); --Kết quả trả về là 10
		SELECT ROUND(10.812, 2); --Kết quả trả về là: 10.81
	Sắp xếp theo thứ tự:
		> SELECT columnName1, columnName2,... FROM tableName ORDER BY columnName1 [DESC|ASC], columnName2[DESC|ASC]
		SELECT id, name FROM student ORDER BY id DESC;
		Các constraint:
			DESC: giảm (đối với kí tự thì xét kí tự đầu tiên)
			ASC: tăng, mặc định (đối với kí tự thì xét kí tự đầu tiên)
	Đảm bảo dữ liệu không trùng nhau:
		> SELECT DISTINCT columnName1, columnName2,... FROM tableName
		Kết hợp cả columnName1 và columnName2 để làm điều kiện >= chỉ một trường hợp columnName
Lọc dữ liệu
	So sánh số lượng lớn: 
		(Không khuyến khích dùng vì nó quét khá chậm)
		> SELECT columnName1, columnName2,... FROM tableName WHERE columnName1 IN (constraint1, constraint2)
			SELECT first_name, last_name FROM actor WHERE first_name IN ('PENELOPE','NICK');
	Kiểm soát dữ liệu là chuỗi kí tự:
		> SELECT columnName1, columnName2,... FROM tableName WHERE columnName LIKE 'A__B%'
		với _ là các kí tự trống để kiểm soát số kí tự
		với % là tự do về số kí tự
		SELECT id, name FROM students WHERE height >=170 AND (name like 'B%' or name like 'b%');
			hoặc SELECT id, name FROM students WHERE height > 170 AND lower(name) like 'B%';
			hoặc SELECT id, name FROM students WHERE height > 170 AND upper(name) like 'b%';
			Ngoài ra, còn có ILIKE: không phân biệt chữ hoa hay thường và NOT LIKE: không giống LIKE
	Giới hạn vùng số:
		> SELECT columnName1, columnName2,... FROM tableName WHERE columnName BETWEEN min AND MAX
		SELECT * FROM actor WHERE birth_year BETWEEN 1990 AND 1999 ORDER BY first_name ASC;
	Giới hạn số lượng kết quả
		> SELECT columnName FROM tableName WHERE constraint LIMIT n
		với n là số lượng, nếu n là 0 thì trống kết quả, nếu n là NULL thì LIMIT không tồn tại. Các kết quả này dựa trên constraint
		Bỏ qua m phần tử đầu trước n:
		> LIMIT n OFFSET M;
	Là kí tự NULL:
		> columnName IS NULL| IS NOT NULL;
		SELECT name, age FROM Students WHERE age IS NULL
Gộp nhiều bảng
[JOIN method](./image/JoinMethod.jpg)
	* INNER JOIN: Các kết nối có liên quan đến nhau
	* LEFT/RIGHT JOIN: ưu tiên một bên
	* FULL OUTER JOIN: Lấy toàn bộ dữ liệu có liêu quan 
[FULL OUTER JOIN](./image/fullOuterJoinOperation.png)
	Gộp bảng với dựa vào trường dữ liệu trùng nhau:
		>SELECT tableName1.columnName1, tableName1.columnName2,..., tableName2 FROM columnName1 INNER columnName2 ON tableName1.columnNameConnect = tableName.columnNameConnect
		Dựa vào trùng vùng dữ liệu giữa các columnNameConnect
		SELECT students.name, address.district FROM students INNER address ON students.codeAddress = address.idAddress
	Thay thế dữ liệu từ cột này bằng cột kia nếu NULL:
		> SELECT columnName1, columnName2,..., COALESCE(columnNameReplaced, columnNameReplacing, 'Unknown') AS columnNameReplaced FROM tableName;
		Thay thế theo thứ tự, nếu columnNameReplaced = NULL -> columnNameReplacing = NULL -> 'Unknown'
		Đối với các phép kết
			> COALESCE(cities.country, 'unknown') AS country
			thay vì COALESCE(cities.country, 'unknown') AS cities.country sẽ báo lỗi, phép COALESCE sẽ làm columnName sau AS trở thành tên cột kết quả chứ không phải cột tính tonas
	Kết trái:
		Kết trái là lấy toàn bộ dữ liệu bên trái + các dữ liệu liên quan bên phải|NULL(có thể dùng COALESCE() để thay giá trị NULL) > Được dùng khi bảng bên phải mang ý nghĩa bổ sung
		> SELECT tableName1.columnName1, COALESCE(tableName2.columnName1, 'unknown') AS columnName1 FROM tableName1 LEFT JOIN tableName2 ON tableName1.columnNameConnect = tableName2.columnNameConnect;
		* Tương tự có kết phải RIGHT JOIN
	Tự kết bản thân:
		SELECT a.columnName, b.columnName FROM tableName1 a [INNER] JOIN tableName2 b ON a.columnNameConnect = b.columnNameConnect 
		> SELECT  a.fullName firstCustomer, b.fullName secondCustomer FROM customer a INNER JOIN customer b on a.city = b.city AND a.first_name <> b.first_name ORDER BY first_customer;
		> Có thể dựa vào so sánh id, năm, hoặc mã code,...
Phân nhóm dữ liệu
	Tính tổng cột:
		> SELECT SUM(columnName) AS newColumnName FROM tableName Where constraint
		SELECT sum(coalesce(demand_loss, 0)) MRO_demand_loss FROM grid WHERE region = 'MRO';
	Tìm min, max, trung bình cột:
		> SELECT MIN|MAX|AVG(columnName) AS newColumnName FROM tableName Where constraint
		Đối với AVG() thường đi kèm với hàm ROUND() để làm tròn số
		SELECT
		COALESCE(MIN(affected_customers), 0) AS min_affected_customers, COALESCE(MAX(affected_customers), 0) AS max_affected_customers, COALESCE(ROUND(AVG(affected_customers), 3), 0) AS avg_affected_customers FROM grid;
	Gom nhóm dữ liệu:
		Đôi lúc việc gộp các cột dữ liệu từ bảng này với bảng kia tạo ra các lựa chọn đa dạng dù không có trường dữ liệu chung để ghép nối, tuy nhiên, việc ghép nối cũng có những qui tắc sắp xếp đầu ra riêng để tạo ra nhưng kết quả thông nhất chung
		> SELECT a.columnName1, b.columnName2 FROM tableName1 a, tableName2 b GROUP BY b.columnName2, a.columnName1 ORDER BY B.columnName2;
		SELECT d.department_name, e.name FROM departments d, employees e GROUP BY e.name, d.department_name ORDER BY d.department_name;  
		Gộp d.department_name và e.name tự do, tuy nhiên ưu tiên e.name theo nhóm dữ liệu đầu, d.department_name theo nhóm dữ liệu thứ tiếp theo kiểu(1a, 1b, 1c, 2a, 2b, 2c), ở đây không có loại trừ các dữ liệu lạ với mệnh đề Where
		* Có thể kết hợp với các hàm tính toán theo qui tắt: 
		* Có thể dùng HAVING để lọc dữ liệu lần nữa đối với các group, có thể dùng các hàm tính toán
			> xét Where để lọc các dữ liệu đơn thuần > xét group by gộp nhóm theo thứ tự các loại giống nhau > tính toán > áp dụng lệnh having
Truy vấn con:
	> Tạo ra một bảng|kết quả|tham số mới để làm điều kiện truy vấn con cho truy vấn khác
	> SELECT FROM WHERE (SELECT FROM WHERE(...)) ORDER BY;
	[NOT]EXISTS(constraint): Kiểm tra sự tồn tại của một dòng hàng dữ liệu, có thể dùng bảng đã khai báo từ truy vấn cha cho truy vấn con
	SELECT * FROM students WHERE EXISTS (
	    SELECT club_id 
	    FROM clubs WHERE clubs.id = students.club_id
	) ORDER BY students.id;
	trong truy vấn con có thể SELECT TRUE|1 hoặc NOT NULL|0 để thay cho kết quả so sánh
	SELECT department_name FROM departments	WHERE NOT EXISTS(
	    SELECT NOT NULL FROM employees
	    WHERE employees.department_id = departments.id
	)
	ORDER BY id;
Ví dụ:
	* Lưu trữ thông tin nợ của một ngân hàng:
		CREATE TABLE program (
		    id TEXT PRIMARY KEY,
		    max_amount NUMERIC(10,2) NOT NULL
		);
		CREATE TABLE loan (
		    bank_id SMALLINT NOT NULL,
		    bank_zip TEXT NOT NULL,
		    approval_date DATE NOT NULL,
		    borrower_id SMALLINT NOT NULL,
		    gross_approval NUMERIC(10,2) NOT NULL,
		    program_id TEXT NOT NULL,
		    term_in_months SMALLINT,
		    intial_interest_rate NUMERIC(10,2) NOT NULL,
		    PRIMARY KEY (approval_date, bank_id, borrower_id),
		    FOREIGN KEY (bank_id) REFERENCES bank(id),
		    FOREIGN KEY (program_id) REFERENCES program(id),
		    FOREIGN KEY (borrower_id) REFERENCES borrower(id)
		);
Thuật ngữ:
	\*: asterisk


Phân tích:
	* dùng case when tổng quát:
		SELECT
		us.id,ct.country , case when country = null then 'unknown'
		else country end 
		as country --coalesce(ct.country,'unknown') as country
		FROM
		users as us
		LEFT JOIN
		cities as ct
		using(city)
		ORDER BY
		id
		;