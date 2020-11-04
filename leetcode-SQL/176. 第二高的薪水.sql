-- ifnull语句的使用
select ifnull(
    (select distinct Salary 
    from Employee order by Salary desc limit 1 offset 1),
    null
) as SecondHighestSalary 