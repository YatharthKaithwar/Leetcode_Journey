# Write your MySQL query statement below
SELECT
    e.name AS Employee,
    d.name AS Department,
    e.salary AS Salary
FROM
    Employee e
JOIN
    Department d ON e.departmentId = d.id
WHERE
    (e.departmentId,e.salary) IN (
        SELECT
        departmentId,MAX(salary)
        FROM
        Employee
        GROUP BY
        departmentId
    )
