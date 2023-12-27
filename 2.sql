DROP DATABASE IF EXISTS student_104;
CREATE DATABASE student_104;
USE student_104;
CREATE TABLE IF NOT EXISTS Student (
    sid VARCHAR(25) primary key,
    name VARCHAR(35) not null,
    branch VARCHAR(25) not null,
    semester int not null,
    address VARCHAR(255),
    phone VARCHAR(35),
    email VARCHAR(50)
);
INSERT INTO Student VALUES 
("1","A","CSE",5,"Bogadi","9432615389","anA@gmail.com"),
("2","B","EC",5,"Banglore","9776142539","beB@gmail.com"),
("3","C","CSE",5,"Kuvempunagar","9437465882","csCE@gmail.com"),
("4","D","EI",5,"Hebbal","93516264738","dh@gmail.com");
UPDATE Student SET address="Vijaynagar" where sid ="2";
SELECT * FROM Student;
delete from Student where sid = "4";
SELECT * FROM Student;
SELECT * from Student where branch="CSE";
SELECT * from Student where branch="CSE" and address="Kuvempunagar";
