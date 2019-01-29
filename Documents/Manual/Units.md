## Creating Units

1. Create a new RTSPawn or RTSCharacter blueprint.
1. Add a static or skeletal mesh and setup its location, rotation and scale as usual.
1. Setup collision (e.g. Capsule Collision) as usual.
1. Add a movement component (e.g. FloatingPawnMovement or CharacterMovement) and 
set up its speed properties as usual.
1. Set the pawn AI controller class to your RTSPawnAIController.
1. Add an RTSSelectableComponent, and set its selection circle material (e.g. to M_RTSSelectionCircle) and selection sound.
1. Add an RTSOwnerComponent.
1. Ensure Pawn > Auto Possess AI is set to "Placed in World or Spawned".
1. You may want to disable the collision of your mesh and rely on its capsule instead.
1. Add an RTSNameComponent and set its localized name if you want to show it in any kind of ingame UI. 
1. Add an RTSPortraitComponent and set its portrait if you want to show it in any kind of ingame UI.