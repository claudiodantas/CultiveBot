app.controller('inicioCtrl', inicioController);

function inicioController($rootScope, $location){
   $rootScope.activetab = $location.path();
}
