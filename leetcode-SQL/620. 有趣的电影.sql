-- 简单过滤、排序
select * from cinema where description != 'boring' and id%2=1 order by rating desc