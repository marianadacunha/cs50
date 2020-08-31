SELECT title, rating
FROM movies JOIN ratings ON movies.id = ratings.movie_id
WHERE year = "2010"
ORDER BY rating DESC, title; -- after being ordered by rating, it will be ordered by title