#DUPLICATES in database
# https://leetcode.com/problems/duplicate-emails/
select Email from Person group by email having count(*) > 1;

#COMBINE TWO TABLES
# https://leetcode.com/problems/combine-two-tables/
Select FirstName, LastName, City, State from Person left join Address on Person.PersonId = Address.PersonId

# EMPLOYEE EARNING MORE THAN MANAGERS
# https://leetcode.com/problems/employees-earning-more-than-their-managers
Select a.Name as Employee from Employee as a, Employee as b where a.ManagerId = b.id and a.Salary > b.Salary
OR
Select a.Name as Employee from Employee as a join Employee as b on a.ManagerId = b.id where a.Salary > b.Salary

# Customers Who Never Order
#https://leetcode.com/problems/customers-who-never-order
Select Name as Customers from Customers left join Orders on Customers.id = Orders.CustomerId where Orders.CustomerId is NULL
OR
SELECT Name as Customers from Customers WHERE NOT EXISTS (SELECT * FROM Orders WHERE Customers.Id = Orders.CustomerId)
OR
Select Name as Customers from Customers where Customers.id NOT IN (select CustomerId from Orders)

# Rising temperature
# https://leetcode.com/problems/rising-temperature
Select a.Id as Id from Weather a, Weather as b 
where a.Temperature > b.Temperature AND TO_DAYS(a.DATE)-TO_DAYS(b.DATE)=1
OR
SELECT a.Id FROM Weather AS a, Weather AS b
WHERE DATEDIFF(a.Date, b.Date)=1 AND a.Temperature > b.Temperature