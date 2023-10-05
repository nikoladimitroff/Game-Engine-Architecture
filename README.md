A repo containing the learning materials for the course
'Game Engine Architecture with UE' taught at the University of Sofia.

See the lectures rendered at
[nikoladimitroff.github.io/Game-Engine-Architecture](http://nikoladimitroff.github.io/Game-Engine-Architecture)

See the Action RPG sample project at
https://github.com/k1p1/UE4TopDownARPG

See the SUSI sample project at
https://github.com/nikoladimitroff/UE4_SusiPlugin


## Authors

* [Yours truly](https://github.com/nikoladimitroff)
* [Aleksandar Angelov](https://github.com/Alekssasho)
* [Viktor Ketipov](https://github.com/k1p1)

The course is supported by [Ubisoft Sofia](https://ubisoft.com) and [Kipi Interactive](http://www.kipiinteractive.com/).

## Contribution

We welcome PRs. To run the slides locally:

1. Read the docs of [Reveal.js](https://revealjs.com/#/) to understand how the syntax works
1. Clone the repo
1. Run an http server in the directory *containing* the repo. If the repo is in *repos/Game-Engine-Architecture*, then run the server in *repos*, ***NOT*** in *Game-Engine-Architecture*.

    - If you have nodejs installed (recommended):

    ```cmd
    npm install http-server -g
    cd repos
    http-server -p 8080
    ```

    - If you have python installed:

    ```cmd
    python -m SimpleHTTPServer 8080
    ```

1. Open [http://localhost:8080/Game-Engine-Architecture](http://localhost:8080/Game-Engine-Architecture)
1. Modify the slides as you want, CTRL + F5 in the browser to see the changes
1. If you are adding local resources, you need to put them in both *lectures/resources/<yourdir>* and in *revealjs/resources/<yourdir>*.

### Conventions

* snake_case.jpg for file names
* prefer local resources to external online resources, as externals can go missing
* do add sources
* the main branch for this repo is *gh-pages* as we use github pages
to host the lectures

## Notes

Don't update revealjs blindly - there are custom changes to the reveal.js/highlight.js plugin, marked with `// GEA`.
