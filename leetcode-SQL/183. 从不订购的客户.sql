-- 使用子查询
select Name as Customers from Customers where Id not in (select distinct CustomerId from Orders)