app.controller('cameraCtrl', cameraController);

function cameraController($rootScope, $location){
   $rootScope.activetab = $location.path();
}
