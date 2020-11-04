-- 外联结 outer join
select FirstName, LastName, City, State from Person left outer join Address on Person.PersonId = Address.PersonId
