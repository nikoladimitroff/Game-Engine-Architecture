# Homework 1

To have you start working on your course project, your first homework
is to decide on what you are going to do, contact us via
[this form][google_form] and make a repository in github
with your project.

## Formal requirements

1. Come up with an idea for your plugin.
    - The plugin must be adding functionality to UE.
    - Content is allowed, but must not be the focus of the project.
    - Think of a game you'd like to create / enhance and then
    think of a subsystem of which you can implement as a plugin.
    - Your idea must not be trivially accomplishable. Once you fill
    the form, we'll contact you back requesting that you increase
    its complexity if we don't think it's hard enough. If fill
    the form late and there's no time to discuss the idea, we'll
    increase the complexity as we see fit.
    - You are allowed to reimplement something already existing
    in UE but you must do so in a manner that's better in some way
    (performance, usability, features).
    - Projects that deal with low-level systems (such as RHI) will
    get more points.
    - Plugins that also provide editor integration (such as adding buttons
    or menus inside the editor) will get more points.
    - You can always increase the set of features of your idea later
    if something else comes to your mind.
1. Fill [the form][google_form]. You can only submit a single response
but you can edit it any time before the final date. Any submission
done post the final date will be invalid (and garbage collected).
2. Create a repository in github of a UE game containing the following:
    1. The minimal sufficient folders to have the game.
    You'll use the game as a testing / demo playground.
    1. A plugin in the game's *Plugins* folder. Remember
    that you can use the Plugin Project Creation Wizard
    (Go to *Edit* -> *Plugins* -> *New Plugin*).
    1. You are allowed to fork the entire engine and make
    changes to the source code if you need to (UE has
    bugs too) but for this the repository ***MUST*** be
    private. Also, if you could not do that, it'd be great
    as it's much easier to manage.
    1. Please don't include unncessary folders and files.
    Refer to the [.gititgnore](https://gist.github.com/nikoladimitroff/c29f766a6a8ee59c3ba2)

Both task must be done **BEFORE** 19:15 on 21.04.2016 (Thursday)
(the start of the lecture).

Keep in mind that this task counts as homework. Failing to accomplish
the tasks will affect your final score.

## Example projects

1. Flocking behaviour - simulate the movement and interaction
of flocks, herds, crowds. Add actor components, allow for components
to be grouped and for the flock to change shape (triangle, circle, rect, etc.).
See this [demo for example](http://nikoladimitroff.github.io/canvas-demos/flocking.html)
1. Inventory - provide an actor component that allows for managing an character
inventory. Possible features may include an UMG / Slate widget for visualizing it, the ability
to pick up, throw and drop items and to manage space for them. You can go with a weight system
(like Skyrim), with a space system (like World of Warcraft) or with a volume system (like
Diablo).
1. Crafting system. Possible features may include having a workbench actor with which
you can interact to get a menu open and then craft using some items. Recipes may be
discovered through crafting (like Guild Wars 2) or by teaching / item drops (World of Warcraft,
Elder Scrolls). You don't to implement the inventory from above, neither do you need the items
to be actually visible in the world but you need to provide for a data-driven approach of
specifiying how to combine ingredients into recipes.
1. UI system. Both Slate and UMG are a bit of a pain to use which is why some members of the
community (ahem, ahem) have made alternatives. For example - [BLUI](https://github.com/AaronShea/BLUI)
is an open-source HTML-based solution to the problem. You can go with an already existing format
(e.g. XAML / HTML) or create your own declarative UI syntax.

In general, you can do anything you like to. Hopefully you've already played a game
with modding capabilities (such as Dragon Age, The Elder Scrolls series, Fallout,
The Witcher, WoW, Dark Souls, Heroes of Might and Magic, Civilization, GTA) and
there was something you thought could do better about it. Now it's your time to implement
that idea using UE.

### Getting inpsired

For more inspiration, checkout the website [Nexus Mods](http://www.nexusmods.com/games/?)
which provides a huge list of mods for many games. In particular, its most famous collection
is for [Skyrim](http://www.nexusmods.com/skyrim/?) and as of the time of this writing it provides
over 42 000 mods. I would suggest you
[sort them by endorsements](http://www.nexusmods.com/skyrim/mods/searchresults/?src_order=1&src_sort=0&src_view=1&src_tab=1&src_language=0&page=1&pUp=1)
and scroll through the list until you've found something interesting.

You can also:

* Scroll the forums of your favourite game for fan ideas
* Ask in the UE forums or the facebook community page for something
people would enjoy having as a plugin.


[google_form]: http://goo.gl/forms/NcyZXN87fl