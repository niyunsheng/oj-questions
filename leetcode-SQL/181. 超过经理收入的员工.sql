-- 方法1：where实现多表联结
select e1.Name as Employee from Employee as e1,Employee as e2 where e1.ManagerId = e2.Id and e1.Salary > e2.Salary

-- 方法2：内联结
select e1.Name as Employee from Employee as e1 inner join Employee as e2 on e1.ManagerId = e2.Id and e1.Salary > e2.Salary