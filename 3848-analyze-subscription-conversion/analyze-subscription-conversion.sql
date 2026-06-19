# Write your MySQL query statement below

-- WITH name AS (
--     SELECT ...
-- )
-- name becomes a temporary result table that exists only for that query.


with trial as(
    select  user_id , avg(activity_duration) as trial_avg_duration
    from UserActivity 
    where activity_type="free_trial"
    group by user_id

),

paid as(
    select  user_id , avg(activity_duration) as paid_avg_duration
    from UserActivity 
    where activity_type="paid"
    group by user_id
)

select trial.user_id , round(trial.trial_avg_duration,2) as trial_avg_duration , round(paid.paid_avg_duration ,2) as paid_avg_duration

from trial join paid on trial.user_id=paid.user_id;