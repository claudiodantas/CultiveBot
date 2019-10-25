var app = angular.module('app',['ngRoute']);

app.config(function($routeProvider)
{

   $routeProvider

   .when('/', {
      templateUrl : 'app/views/inicio.html'
   })

   .when('/camera', {
      templateUrl : 'app/views/camera.html'
   })

   .when('/minhasplantas', {
      templateUrl : 'app/views/minhasplantas.html'
   })

   .when('/controleManual', {
      templateUrl : 'app/views/controleManual.html'
   })

   .when('/dadospessoais/conta', {
      templateUrl : 'app/views/dadosPessoaisConta.html'
   })

   .when('/dadospessoais/senha', {
      templateUrl : 'app/views/dadosPessoaisSenha.html'
   })

   .when('/dadospessoais/notificacoes', {
      templateUrl : 'app/views/dadosPessoaisNotificacoes.html'
   })

   .otherwise ({ redirectTo: '/' });
});
