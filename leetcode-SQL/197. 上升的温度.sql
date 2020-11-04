-- 方法1：cross join，然后选择，注意日期函数的应用
-- 最后条件用where实现比在联结条件判断中给on增加条件更快
select w1.id from Weather as w1 cross join Weather as w2 on datediff(w1.recordDate,w2.recordDate) = 1 where w1.temperature > w2.temperature