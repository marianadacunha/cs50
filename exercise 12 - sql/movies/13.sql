SELECT name
FROM people JOIN stars ON stars.person_id = people.id
WHERE name != "Kevin Bacon" -- will not count Kevin Bacon itself
AND movie_id IN ( -- counting only the movies where kevin bacon stars
    SELECT movie_id
    FROM people JOIN stars ON stars.person_id = people.id
    WHERE name = "Kevin Bacon" AND birth = "1958"
)
GROUP BY name, person_id; -- counting by id too, avoiding duplicate names with differents id