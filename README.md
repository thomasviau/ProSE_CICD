# CI sur ProSE

Suivre ce dépot va vous permettre de mettre en place un processus d'intégration continue (CI) sur votre projet ProSE.

Les outils suivants seront mis en place :
* SonarCloud (aka SonarLint)
* CppCheck

## Comptes requis

* Un compte [GitHub](https://github.com)
    * Demander le  [GitHub Student Pack](https://education.github.com/pack/offers). Il permet de créer des dépots privés gratuitement et de faire des build privés sur [Travis CI](https://travis-ci.com).
* Un compte [SonarCloud](https://sonarcloud.io/)
    * Avec la version gratuite, vous pouvez l'utiliser uniquement sur des dépots publics. Autrement, vous pouvez installer [SonarQube](https://www.sonarqube.org/) sur un serveur (intégration avec Travis CI non testée).
* Un compte [Redmine ProSE](http://prose.eseo.fr/redmine)