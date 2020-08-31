SELECT name
FROM people JOIN directors ON directors.person_id = people.id JOIN ratings ON ratings.movie_id = directors.movie_id
WHERE rating >= 9.0
GROUP BY name, person_id; -- counting by id too, avoiding duplicate names with differents id