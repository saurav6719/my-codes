
create database college;
use college;
create table student(
	id int primary key,
    name varchar(50),
    age int not null
);

insert into student values(1,"saurav",20);
insert into student values(2,"shivam", 20);

select * from student;