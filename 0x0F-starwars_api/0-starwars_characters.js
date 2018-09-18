#!/usr/bin/node
const request = require('request');
const args = process.argv.slice(2);
const filmId = args[0];

getFilmCharacters(filmId, 'https://swapi.co/api/people/');

function getFilmCharacters (filmId, endPoint) {
  request(endPoint, function (err, response, body) {
    if (err) {
      console.log(err);
    } else {
      const responseObj = JSON.parse(response.body);
      endPoint = responseObj.next;
      let characters = responseObj.results;
      characters.forEach(function (character) {
        const films = character.films;
        films.forEach(function (film) {
          if (film.includes(filmId)) {
            console.log(character.name);
          }
        });
      });
    }
    if (endPoint) {
      getFilmCharacters(filmId, endPoint);
    }
  });
}
