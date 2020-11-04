-- 注意group by和having的用法
select class from courses group by class having count(distinct student) >= 5