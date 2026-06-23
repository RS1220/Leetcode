# Write your MySQL query statement below

select id , 
sum(case when month='Jan' then revenue END) as Jan_Revenue,
sum(case when month='Feb' then revenue END) as Feb_Revenue,
sum(case when month='Mar' then revenue END) as Mar_Revenue,
sum(case when month='Apr' then revenue END) as Apr_Revenue,
sum(case when month='May' then revenue END) as May_Revenue,
sum(case when month='Jun' then revenue END) as Jun_Revenue,
sum(case when month='Jul' then revenue END) as Jul_Revenue,
SUM(CASE WHEN month = 'Aug' THEN revenue END) AS Aug_Revenue,
    SUM(CASE WHEN month = 'Sep' THEN revenue END) AS Sep_Revenue,
    SUM(CASE WHEN month = 'Oct' THEN revenue END) AS Oct_Revenue,
    SUM(CASE WHEN month = 'Nov' THEN revenue END) AS Nov_Revenue,
    SUM(CASE WHEN month = 'Dec' THEN revenue END) AS Dec_Revenue

    from Department
group by id;