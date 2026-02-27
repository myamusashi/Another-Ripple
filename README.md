# Another-Ripple
This is a Ripple effect in QML, that can be used everywhere. 

<video width="640" height="480" controls>
  <source src="screenrecord.mp4" type="video/mp4">
  Your browser does not support the video tag.
</video>

1. Build this project with cmake:
```
mkdir build && cd build && cmake ..
```

2. Install the plugins:
```
cmake --install .
```

3. Use as an item inside another item:
```
import AnotherRipple
import QtQuick

Item{
     width:100
     height:100

      SimpleRipple{
          anchors.fill: parent;
          color: "#50ffa070"
      }
}
```

*properties:*

`acceptEvent` 
This is false by default. if you change this to true, it means that Ripple item accepts the click(pressed) events and prevent them to receive to bottom layouts.

`color`
This property sets Color of ripple effect.

`clipRadius`
This property sets radius of Ripple Area to prevent painting out of corner.

`xClipRadius`
This property sets only x in clipRadius property specially.

`yClipRadius`
This property sets only y in clipRadius property specially.

*node:* by default clipRadius sets both x and y

*methods:*

`pressed(int x , int y)` 
It is used when an item like MouseArea masks Ripple item and doesn't allow clicking(pressing) Ripple item. you can call this and pass mouse x and y to it. 
