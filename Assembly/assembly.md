```
> #h1
> #h2
> ...
> *in đậm*
> **bôi đậm*
> ***in nghiêng và bôi đậm***
> `thêm code`
> [title](link//anh)
> gạch đầu dòng:
	> *
	> *
	> *
	> hoặc
	> 1.
	> 2.
	> 3.
> gạch kẻ ***
> highlight text >
> \
> {@youtube: Youtube ID or url}
```
> nasm -f elf64 -o <filename>.o <filename>.asm
	
> ld -o <filename> <filename>.o

##Chapter 1: Giới thiệu Assembly 
Mỗi máy tính cá nhân đều có chung các tính năng nhằm quản lý và xử lý: toán học, logic, điều khiển các hoạt động
Lợi ích khi học Assembly
* Hiểu biết về hệ điều hành, vi xử lý và BIOS
* Hiểu biết về dữ liệu bên trong bộ nhớ và các thiết bị
* Học cách truy cập và thực hiện các chỉ dẫn
* Học cách truy cập và xử lý các dữ liệu
* Học cách tạo một chương trình tương tác với các thiết bị

Các mục tiêu khác
* Sử dụng bộ nhớ tối thiểu và thời gian thực hiện
* Tương tác thiết bị nhanh hơn
* Đánh giá kĩ các chương trình
* Hiểu được cách một chương trình hoạt động và sử dụng bộ nhớ
Cơ bản về phần cứng máy tính

Mỗi phần cứng máy tính bao gồm:
* Vi xử lý: Có 2 trạng thái ON(1) hoặc OFF(0), và mọi thứ được biểu diễn bằng các bit, có thể ghép 8 bit lại tạo thành 1 byte. Tất cả các giá trị đều được biểu diễn ở trạng thái 1(odd hay ON), và các thông báo lỗi được biểu diễn ở trạng thái 0(even hay OFF)
* Bộ nhớ: 
> Word: Mỗi 2 byte
> Doubleword: mỗi 4 byte
> Quadword: mỗi 8 byte
> Paragraph: một khu vực được biểu diễn với mỗi 16byte
> Kilobyte: 1024 byte
> Megabyte: 1 048 576 byte
* Các danh mục đăng ký: Là nơi nắm giữ dữ liệu và địa chỉ. Chúng copy từ bên ngoài và đưa vào bên trong bộ nhớ, sau đó được dùng cho quá trình thực hiện chương trình

Biểu diễn số ở dạng binary:
> Hãy nhớ rằng giá trị chạy từ 0 đến 255, đồng nghĩa với 256 giá trị với mỗi byte

Biểu diễn số ở dạng hexadecimal
> Hãy nhớ ràng có 16 hằng số để biểu diễn 0123456789ABCDEF

Thao tác nhị phân
```
0 + 0 = 0
1 + 0 = 1
1 + 1 = 10
1 + 1 + 1 = 11
```
```
60  = 00111100
+42 = 00101010
102 = 01100110
```
Đảo một số thành số âm cần thực hiện quy tắc "Đảo ngược số" > "Thêm 1"
```
53    = 00110101
r(53) = 11001010
+1    = 00000001
-53   = 11001011
```
```
53 - 42 = 
42    = 00101010
r(42) = 11010101
+1    = 00000001
-42   = 11010110
53    = 00110101
-42+53= 00001011
11  
```

Quy trình dữ liệu trong bộ nhớ
Thực hiện vòng lặp gồm 3 bước:
* Nạp chỉ dẫn vào bộ nhớ
* Giải mã hoặc xác định các chỉ dẫn
* Thực thi các chỉ dẫn

> Vi xử lý có thể chấp nhận 1 hoặc nhiều byte tại cùng một thời điểm. Tuy nhiên các dữ liệu này được cắt nhỏ thành mỗi 2 byte và đảo ngược thứ tự trước khi được nạp vào bộ nhớ

```
Các doanh mục tạm thời mang giá trị 0725
Dữ liệu sẽ được cắt nhỏ thành mỗi 2 byte (07)(25)
Nạp vào với thứ tự ngược lại > (25) > (07)
Bộ nhớ mang giá trị |25||07|
```

Có 2 loại địa chỉ:
* Địa chỉ tuyệt đối
* Địa chỉ rời rạc(hoặc phần bù, offset)

##Chapter 2: Cài đặt môi trường
##Chapter 3: Cú pháp cơ bản
Một chương trình assembly được chia làm 3 phần
* data
> Chứa dữ liệu không thể thay đổi trong suốt thời gian chạy, hay còn gọi là hằng số. Các dữ liệu này có thể là hằng số, tên file, kích thước

> section.data

* bss
> Chứa các dữ liệu có thể thay đổi, hay còn gọi là biến

> section.bss

* text
> Là nơi chứa code, bắt đầu của code tại được khai báo là gắn thêm global

```
section.text
	global _start
_start:
```

> section.text

Comments:
> Nó bắt đầu bằng dấu semicolon ;

> add eax, ebx	; this is a comments

Các câu lệnh trong Assembly
* Các chỉ dẫn hoặc thực thi chỉ dẫn
* Các lệnh trung gian không thực thi hay yêu cầu thực thi
* Các hàm 

```
section	.text
   global _start     ;must be declared for linker (ld)
	
_start:	            ;tells linker entry point
   mov	edx,len     ;message length
   mov	ecx,msg     ;message to write
   mov	ebx,1       ;file descriptor (stdout)
   mov	eax,4       ;system call number (sys_write)
   syscall        ;call kernel
	
   mov	eax,1       ;system call number (sys_exit)
   syscall        ;call kernel

section	.data
msg db 'Hello, world!', 0xa  ;string to be printed
len equ $ - msg     ;length of the string
```

> Các phần code được phân ra ngay tại "section"

> Từ khóa global để đánh dấu điều bắt đầu khi code thực thi

> Có thể thay thế section bằng segment

```
segment .text	   ;code segment
   global _start    ;must be declared for linker 
	
_start:	           ;tell linker entry point
   mov edx,len	   ;message length
   mov ecx,msg     ;message to write
   mov ebx,1	   ;file descriptor (stdout)
   mov eax,4	   ;system call number (sys_write)
   int 0x80	   ;call kernel

   mov eax,1       ;system call number (sys_exit)
   int 0x80	   ;call kernel

segment .data      ;data segment
msg	db 'Hello, world!',0xa   ;our dear string
len	equ	$ - msg          ;length of our dear string
```

##Chapter 4: Các phần bộ nhớ

Được chia làm 3 phần:
1. Data segment: Là nơi phân vùng chứa dữ liệu ở dạng tĩnh, không thể mở rộng xuyên suốt chương trình
* Data: '.data' phân vùng vừa với kích thước dữ liệu được khai báo
* Bss: '.bss' phân vùng thêm các buffers được zero-filled, có thể mở rộng vào các buffers này
2. Code segment: Tương tự như '.text section', là nơi chứa code và cũng là phân vùng cố định
3. Stack: Là nơi chứa dữ liệu của các hàm và các chương trình con

##Chapter 5: Ký gửi dữ liệu

> Hoạt động xử lý của vi xử lý đều liên quan đến đọc và ghi dữ liệu, tuy nhiên quá trình này tương đối chậm, nên một bộ nhớ được thiết kế trong vi xử lý có hạn mức cố định nhưng tốc độ tương đối nhanh gọi là registers

Thường chia thành 3 loại registers:
1. General registers
	* Data registers:(Trong kiến trúc 32bit) Gồm 4 registers được sử dụng cho tính toán, logic và xử lý
	> Ví dụ: EAX mang 32 bit, được chia thành 2 AX mang 16 bit, mỗi AX được chia thành \_H và \_L được phân thành vùng trước vùng sau mang 8 bit

		1. EAX(AX(AH + AL)* 2): Được sử dụng trong hầu hết các phép toán và trong input/output(primary Accumulator: Bộ tích điện sơ cấp)
		2. EBX(BX(BH + BL)* 2): Thường được sử dụng để tuyến tính địa chỉ(Base: Cơ số, đường dẫn)
		3. ECX(CX(CH + CL)* 2): Được sử dụng để đếm giá trị lặp(Count: Đếm)
		4. EDX(DX(DH + DL)* 2): Tương tự như EAX nhưng thường được kết hợp chung với EAX để tính toán các giá trị lớn(Data: Dữ liệu)

	* Point registers:(Trong kiến trúc 32bit) Gồm 3 registers được sử dụng liên quan đến con trỏ
	> Ví dụ: EIP mang 32 bit, được chia thành 2 IP mang 16 bit

		1. EIP(IP* 2): Lưu trữ phần sau của địa chỉ chỉ dẫn tiếp theo, kết hợp với CS tạo thành CS:IP để có được địa chỉ code tiếp theo(Instruction Pointer IP: con trỏ chỉ dẫn)
		2. ESP(SP* 2): Lưu trữ phần sau của địa chỉ giá trị tiếp theo trong stack, kết hợp với SS tạo thành SS:SP để có được địa chỉ giá trị trong stack(Stack Pointer SP: con trỏ trong stack) 
		3. EBP(BP* 2): Lưu trữ phần sau của địa chỉ các giá trị trả về bởi chương trình con, kết hợp với SS tạo thành SS:BP để có được địa chỉ chính xác, hoặc DI:BP hoặc SI:BP là địa chỉ đặc biệt nào đó(Base Pointer SP: con trỏ cơ sở)
	* Index registers:(Trong kiến trúc 32bit) Gồm 2 registers được sử dụng để hỗ trợ trỏ địa chỉ, hoặc đôi lúc là cộng hoặc trừ một giá trị
	> Ví dụ: ESI mang 32 bit, được chia thành 2 SI mang 16 bit
	
		1. Source Index(SI): Được sử dụng để trỏ giá trị đầu của chuỗi
		2. Destination Index(DI): Được sử dụng để trỏ giá trị cuối của chuỗi
2. Control registers
> Được kết hợp từ 32 bit Pointer register và 32 bit flags register

> Các chỉ dẫn được thực hiện dựa vào các lệnh so sánh, tính toán, và trạng thái của cờ lệnh, có thể bao gồm cả kết quả của các điều kiện 

Các flag bit:
	1. Overflow Flag(OF): Đánh dấu tràn bộ nhớ dựa vào so sánh lượng bit đã đăng kí trước và số bit hiện tại
	2. Direction Flag(DF): Xác định phương hướng di chuyển hoặc so sánh của dữ liệu, hoạt động từ trái qua phải khi DF là 0, và khi DF là 1 thì hoạt động từ phải qua trái
	3. Interrupt Flag(IF): Xác định các yếu tố bên ngoài như bàn phím,... có thể làm gián đoạn thực hiện chương trình hay không. Tắt khi IF là 0, và bật khi IF là 1
	4. Trap Flag(TF): Cho phép thực hiện từng lệnh hay không, tương tự như DEBUG. Bật khi TF là 0, và tắt khi IF là 1
	5. Sign Flag(SF): Đánh dấu giá trị có dùng bit đầu tiên để biểu diễn dấu hay không, với 0 là số dương và 1 là số âm. Bật khi SE là 0, và tắt khi SF là 1
	6. Zero Flag(ZF): Trả về kết quả của phép so sánh, với 0 biểu diễn giống và 1 biểu diễn khác
	7. Auxiliary Carry Flag(AF): Khi thực hiện cộng bit, khi 1+1, thì giá trị nhớ dược đặt ở bit 4 và đánh dấu ở bit 3
	8. Parity Flag(PF): Mang giá trị là 0 nếu là số chẵn, và 1 nếu là số lẻ
	9. Carry Flag(CF): Lưu giá trị đầu tiên hay giá trị bên trái của một giá trị

	> 15 14 13 12 11(O) 10(D) 9(I) 8(T) 7(S) 6(Z) 5 4(A) 3 2(P) 1 0(C)
3. Segment registers
	1. Code Segment: Là nơi lưu trữ toàn bộ các chỉ dẫn thực thi hay gọi là code, 16 bit hay CS register dùng để lưu trữ địa chỉ bắt đầu của code
	2. Data Segment: Là nơi lưu trữ dữ liệu, hằng số, khu vực lưu trữ, 16 bit hay DS register dùng để lưu trữ địa chỉ bắt đầu của dữ liệu
	3. Stack Segment: Là nơi chứa dữ liệu đi vào đi ra của hàm con và địa chỉ câu lệnh thực hiện tiếp theo sau nó. Điểm kết thúc được lưu trữ tại Stack segment register hoặc SS register

	> Ngoài ra còn có ES, FS, GS cung cấp thêm các phần để lưu trữ dữ liệu

	> Tất cả các vị trí lưu trữ đều bắt đầu bằng một giá trị hexa 16 và mang giá trị 0, để đánh điểm bắt đầu

	> Bất kì phân vùng lưu trữ nều cũng có các offset dư thừa để phòng trường hợp cần thêm

##Chapter 6: Các hàm gọi
Trong Linux system calls:
* Các câu lệnh gọi được đặt trong EAX register
* Lưu trữ các tham số trong EBX, ECX,...
* Làm gián đoạn chương trình với ký hiệu 80h(0x80)
* Giá trị trả về thường lưu trong EAX register

> Thứ tự lưu trữ các arguments lần lượt là EBX, ECX, EDX, ESI, EDI và EBP

> https://syscalls32.paolostivanin.com/ Từ điển để tra các lệnh

> 4	 sys_write	unsigned int const char* size_t
```
mov	eax,4		; system call number (sys_write)
mov	ebx,1		; file descriptor (stdout)
mov	ecx,msg		; message to write
mov	edx,4		; message length
int	0x80		; call kernel
```

Phân tích đoạn code
```
section .data                           ;Khai báo dữ liệu
   userMsg db 'Please enter a number: ' ;Hiện dòng thông báo được lưu trong userMsg
   lenUserMsg equ $-userMsg             ;Độ dài của dòng userMsg với $- có nghĩa là len(userMsg)
   dispMsg db 'You have entered: '		;Hiện dòng thông báo được lưu trong dispMsg
   lenDispMsg equ $-dispMsg				;Độ dài của dòng dispMsg

section .bss           ;Khởi tạo dữ liệu có thể thay đổi
   num resb 5		;Khởi tạo biến num với 5 byte dữ liệu
	
section .text          ;Code Segment
   global _start
	
_start:                ;User prompt
   mov eax, 4
   mov ebx, 1
   mov ecx, userMsg
   mov edx, lenUserMsg
   int 80h

   ;Read and store the user input
   mov eax, 3
   mov ebx, 2
   mov ecx, num  
   mov edx, 5          ;5 bytes (numeric, 1 for sign) of that information
   int 80h
	
   ;Output the message 'The entered number is: '
   mov eax, 4
   mov ebx, 1
   mov ecx, dispMsg
   mov edx, lenDispMsg
   int 80h  

   ;Output the number entered
   mov eax, 4
   mov ebx, 1
   mov ecx, num
   mov edx, 5
   int 80h  
    
   ; Exit code
   mov eax, 1
   mov ebx, 0
   int 80h
```
##Chapter 7: Các thao tác bộ nhớ 
Có 3 loại địa chỉ:
1. Register addressing: 
> Dùng để cung cấp dữ liệu cho vi xử lý nhanh
```
MOV DX, TAX_RATE   ; Register in first operand
MOV COUNT, CX	   ; Register in second operand
MOV EAX, EBX	   ; Both the operands are in registers
```
2. Immediate addressing
> Dữ liệu được khai báo dạng hằng số
```
BYTE_VALUE  DB  150    ; A byte value is defined
WORD_VALUE  DW  300    ; A word value is defined
ADD  BYTE_VALUE, 65    ; An immediate operand 65 is added
MOV  AX, 45H           ; Immediate constant 45H is transferred to AX
```
3. Memory addressing
	* Direct Memory addressing
		> Là địa chỉ được chỉ định như một phần của chương trình, chỉ định điểm bắt đầu và tính toán các phần bù để dữ liệu được sắp xếp hợp lý và truy cập chính xác. Các địa chỉ này thuộc phần cho phép truy cập của bộ nhớ
		```
		ADD	BYTE_VALUE, DL	; Adds the register in the memory location
		MOV	BX, WORD_VALUE	; Operand from the memory is added to register
		```
	* Direct-Offset addressing
		> Trỏ địa chỉ thông qua phần bù, địa chỉ thực = điểm bắt đầu + số bước nhảy
		```
		BYTE_TABLE DB  14, 15, 22, 45      ; Tables of bytes
		WORD_TABLE DW  134, 345, 564, 123  ; Tables of words
		```
		```
		MOV CL, BYTE_TABLE[2]	; Gets the 3rd element of the BYTE_TABLE
		MOV CL, BYTE_TABLE + 2	; Gets the 3rd element of the BYTE_TABLE
		MOV CX, WORD_TABLE[3]	; Gets the 4th element of the WORD_TABLE
		MOV CX, WORD_TABLE + 3	; Gets the 4th element of the WORD_TABLE
		```
	* Indirect Memory addressing
		> Chỉ định rõ đâu là thao tác [giá trị], đâu là thao tác bộ nhớ
		> Các thao tác phải thông qua gián tiếp, ví dụ chuyển thao tác vào EBX
		```
		MY_TABLE TIMES 10 DW 0  ; Allocates 10 words (2 bytes) each initialized to 0
		MOV EBX, [MY_TABLE]     ; Effective Address of MY_TABLE in EBX
		MOV [EBX], 110          ; MY_TABLE[0] = 110
		ADD EBX, 2              ; EBX = EBX +2
		MOV [EBX], 123          ; MY_TABLE[1] = 123
		```
	BYTE 1, WORD 2, DWORD 4, QWORD 8, TBYTE 10

##Chapter 8: Các biến trong Assembly
	Tạo biến hoặc tạo mảng
	[variable-name]	define-directive initial-value [, initial-value]
```
	Các define-directive:
	DB Byte 		1
	DW Word 		2
	DD DoubleWord 	4
	DQ Quadword		8
	DT TenBytes		10
```
```
choice		DB	'y'
number		DW	12345
neg_number	DW	-12345
big_number	DQ	123456789
real_number1	DD	1.234
real_number2	DQ	123.456
```
Ghi chú:
* Các byte ký tự được lưu dưới dạng hexa
* Các giá trị số được lưu dưới dạng hexa
* Vi xử lý sử dụng kiến trúc little-endian 
* Các số âm được lưu dưới dạng bù 2
* Số thực được lưu dưới dạng 32 hoặc 64 bit tương ứng

Reserve cho phép tạo sẵn một không gian để lưu trữ sẵn và có thể khai báo dưới dạng bậc
```
RESB Byte 			1
RESW Word 			2
RESD DoubleWord 	4
RESQ Quadword		8
REST TenBytes		10
```
Ví dụ:
```
reverseAByte RESB 1
reverseTwoBytes RESB 2
```
Chúng ta có thể khởi tạo nhiều giá trị một lần bằng lệnh TIMES
```
section	.data
stars   times 9 db '*'
```
> *********

##Chapter 9: Hằng số trong Assembly
Có 3 cách gán hằng số:
1. EQU
> Tương tự như gán hằng số trong các ngôn ngữ khác, không thể thay đổi
> CONSTANT_NAME EQU expression
```
TOTAL_STUDENTS equ 50
mov  ecx,  TOTAL_STUDENTS 
cmp  eax,  TOTAL_STUDENTS
LENGTH equ 20
WIDTH  equ 10
AREA   equ length * width
```
2. %assign
> Tương tự như lệnh define, tuy nhiên chỉ gắn số và có thể thay đổi
```
%assign TOTAL 10
%assign TOTAL 20
```
3. %define 
> Tương tự như lệnh define, tuy nhiên có thể gán cả số và chuỗi hoặc ký tự, có thể thay đổi
```
%define PTR [EBP+4]
%define PTR 'a'
```
##Chapter 10: Giới thiệu về số học
Gồm 2 chỉ dẫn tăng giảm:
1. INC
> Tăng giá trị thêm 1, cần chủ ý đang tương tác trên địa chỉ(mặc định đối với biến) hay giá trị(mặc định với register)
2. DEC
> Giảm giá trị thêm 1, cần chủ ý đang tương tác trên địa chỉ(mặc định đối với biến) hay giá trị(mặc định với register)
Gồm 2 lệnh cộng trừ:
1. ADD:
> Cộng 2 giá trị
2. SUB:
> Trừ 2 giá trị

```
 ; moving the first number to eax register and second number to ebx
   ; and subtracting ascii '0' to convert it into a decimal number
	
   mov eax, [num1]
   sub eax, '0'
	
   mov ebx, [num2]
   sub ebx, '0'

   ; add eax and ebx
   add eax, ebx
   ; add '0' to to convert the sum from decimal to ASCII
   add eax, '0'
```
Gồm 2 dạng phép nhân:
> MUL/IMUL multiplier
> Kết quả sẽ được lưu ở giá trị sau
> Vùng lưu trữ sẽ gấp đôi vùng lưu trữ giá trị sau
```
MOV AL, 10
MOV DL, 25
MUL DL
...
MOV DL, 0FFH	; DL= -1
MOV AL, 0BEH	; AL = -66
IMUL DL
```
Gồm 2 dạng phép chia:
> DIV/IDIV divisor
> Kết quả sẽ được lưu ở giá trị sau
> Kết quả được lưu ở giá trị sau, phần dư được lưu ở giá trị trước
> Có thể xảy ra tràn bộ nhớ
```
mov		ax,'8'
sub     ax, '0'
mov 	bl, '2'
sub     bl, '0'
div 	bl
```

##Chapter 11: Giới thiệu về các phép logic 
* AND
	0101 AND 0011 = 0001
	> Kết quả là 1 nếu được nạp bởi 2 số 1, ngược lại đều là 0
	> Một chương trình kiểm tra chẵn lẻ cơ bản
	```
	section .text
   	global _start            ;must be declared for using gcc
	
	_start:                     ;tell linker entry point
	   mov   ax,   8h           ;getting 8 in the ax 
	   and   ax, 1              ;and ax with 1
	   jz    evnn
	   mov   eax, 4             ;system call number (sys_write)
	   mov   ebx, 1             ;file descriptor (stdout)
	   mov   ecx, odd_msg       ;message to write
	   mov   edx, len2          ;length of message
	   int   0x80               ;call kernel
	   jmp   outprog

	evnn:   
	  
	   mov   ah,  09h
	   mov   eax, 4             ;system call number (sys_write)
	   mov   ebx, 1             ;file descriptor (stdout)
	   mov   ecx, even_msg      ;message to write
	   mov   edx, len1          ;length of message
	   int   0x80               ;call kernel

	outprog:

	   mov   eax,1              ;system call number (sys_exit)
	   int   0x80               ;call kernel

	section   .data
	even_msg  db  'Even Number!' ;message showing even number
	len1  equ  $ - even_msg 
	   
	odd_msg db  'Odd Number!'    ;message showing odd number
	len2  equ  $ - odd_msg
	```
* OR
	> 0101 or 0011 = 0111
	> Trả về giá trị 0 khi cả 2 đều là 0, còn lại trả về 1
	> Lưu 1 giá trị vào ô nhớ
	```
	section .text
   	global _start            ;must be declared for using gcc
	
	_start:                     ;tell linker entry point
	   mov    al, 5             ;getting 5 in the al
	   mov    bl, 3             ;getting 3 in the bl
	   or     al, bl            ;or al and bl registers, result should be 7
	   add    al, byte '0'      ;converting decimal to ascii
		
	   mov    [result],  al
	   mov    eax, 4
	   mov    ebx, 1
	   mov    ecx, result
	   mov    edx, 1 
	   int    0x80
	    
	outprog:
	   mov    eax,1             ;system call number (sys_exit)
	   int    0x80              ;call kernel
		
	section    .bss
	result resb 1
	```
* XOR
	> 0101 XOR 0011 = 0110
	> Trả về 1 khi các giá trị khác nhau, còn lại trả về 0
	> Dùng để reset các cờ về 0
	> XOR EAX, EAX
* TEST
	> Tương tự như AND, tuy nhiên giá trị ban đầu sẽ không bị thay đổi mà lưu ở một cờ lệnh nào đó
* NOT
	>Đảo ngược giá trị binary
##Chapter 12: Điều kiện trong Assembly
1. Nhảy không điều kiện
	> JMP
2. Nhảy có điều kiện
	> Đọc theo câu lệnh
	```
	INC	EDX
	CMP	EDX, 10	
	JLE	LP1 
	; nhảy nếu EDX less or equal than 10
	```
	> Các thay đổi được lưu trong biến IP
	Các lệnh và cờ tương ứng đối với dữ liệu có dấu
	1. JE/JZ: ZF
	2. JNE/JNZ: ZF
	3. JG/JNLE: OF, SF, ZF
	4. JGE/JNL: OF, SF
	5. JL/JNGE: OF, SF
	6. JLE/JNG: OF, SF, ZF
	> Các lệnh chỉ có so sánh bằng hoặc không bằng 0 thì chỉ dùng lệnh ZF
	> Các lệnh bé hơn hoặc bằng hoặc không bé hơn hoặc bằng dùng thêm lệnh ZF
	Các lệnh và cờ tương ứng đối với dữ liệu không dấu
	1. JE/JZ: ZF
	2. JNE/JNZ: ZF
	3. JA/JNBE: CF, ZF
	4. JAE/JNB: CF
	5. JB/JNAE: CF
	6. JBE/JNA: AF, CF
	Các lệnh check cờ và giá trị được lưu ở
	1. JXCZ: none - Jump if CX is Zero
	2. JC: CF - Jump if carry
	3. JNC: CF - Jump if No Carry
	4. JO: OF - Jump if Overflow
	5. JNO: OF - Jump if No Overflow
	6. JP/JPE: PF - Jump Parity or Jump Parity Even
	7. JNP/JPO: PF - Jump No Parity or Jump Parity Odd
	8. JS: SF - Jump Sign
	9. JNS: SF - Jump No Sign
##Chapter 13: Câu lệnh lặp trong Assembly
> Gán số vòng lặp cho ECX, sau đó tạo hàm lặp, gọi lệnh 'loop tenHamLap' là chương trình tự lặp
```
	mov ECX,10
	l1:
	<loop body>
	loop l1
```
##Chapter 14: Số trong Assembly
##Chapter 15: Chuỗi trong Assembly
##Chapter 16: Mảng trong Assembly
##Chapter 17: Thủ tục trong Assembly
##Chapter 18: Đệ quy trong Assembly
##Chapter 19: Hàm con trong Assembly
##Chapter 20: Thao tác file
##Chapter 21: Quản lý bộ nhớ
##Note:
0xD:tab
0xA:enter
ASCII có dạng 00x...
Số có dạng 0x
muốn convert(Chuyển đổi qua lại) chỉ cần add  ,'0' hoặc sub  ,'0'
độ dài của một chuỗi được đếm bằng câu lệnh $- 