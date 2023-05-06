with r as (
  select *
  from Movies
  join MovieRating using (movie_id)
  join Users using (user_id)
), ur as (
  select name, 
    count(*) as count_ratings, 
    max(count(*)) over () as max_count_ratings
  from r 
  group by name
  order by 1
), mr as (
  select title, 
    avg(rating) as avg_rating, 
    max(avg(rating)) over () as max_avg_rating
  from r 
  where created_at >= '2020-02-01' and created_at < '2020-03-01' 
  group by title 
  order by 1
)
(
  select name as results
  from ur 
  where count_ratings = max_count_ratings 
  limit 1
)
union all
(
  select title as results
  from mr 
  where avg_rating = max_avg_rating 
  limit 1
)
/* select * from r order by movie_id, rating, created_at */