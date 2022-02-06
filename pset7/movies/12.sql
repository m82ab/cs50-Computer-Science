select title from people join stars on stars.person_id = people.id join movies on stars.movie_id = movies.id
where name = "Helena Bonham Carter" and movie_id IN
(select movie_id from people join stars on stars.person_id = people.id where name = "Johnny Depp")