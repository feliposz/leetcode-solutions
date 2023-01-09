# Write your MySQL query statement below
select Users.name, sum(Transactions.amount) as balance
from Users 
inner join Transactions on Users.account = Transactions.account
group by Users.name
having sum(Transactions.amount) > 10000;