SELECT title
FROM movies JOIN stars ON stars.movie_id = movies.id JOIN people ON people.id = stars.person_id
WHERE name = "Johnny Depp"

INTERSECT -- it will count only the movies where both actors are, like a venn diagram

SELECT title
FROM movies JOIN stars ON stars.movie_id = movies.id JOIN people ON people.id = stars.person_id
WHERE name = "Helena Bonham Carter"