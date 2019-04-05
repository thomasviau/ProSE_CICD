# CI sur ProSE

Suivre ce dépot va vous permettre de mettre en place un processus d'intégration continue (CI) sur votre projet ProSE.

Les outils suivants seront mis en place :
* SonarCloud (aka SonarLint)
* CppCheck

## Avertissement

Pensez à vérifier avec votre client si vous avez l'autorisation d'utiliser tous ces outils. Beaucoup d'entre eux nécessiteront de déployer le code sur des dépots **publics** en version gratuite !

## Comptes requis

* Un compte [GitHub](https://github.com)
    * Demander le  [GitHub Student Pack](https://education.github.com/pack/offers). Il permet de créer des dépots privés gratuitement et de faire des build privés sur [Travis CI](https://travis-ci.com).
* Un compte [SonarCloud](https://sonarcloud.io/)
    * Avec la version gratuite, vous pouvez l'utiliser uniquement sur des dépots publics. Autrement, vous pouvez installer [SonarQube](https://www.sonarqube.org/) sur un serveur (intégration avec Travis CI non testée).
* Un compte [Redmine ProSE](http://prose.eseo.fr/redmine)
* Un compte [Travis CI](https://travis-ci.com)

## Installation

### GitHub

1. Créez un dépot public (sinon SonarCloud ne pourra pas fonctionner).
2. Pensez à lier votre IDE à Git (menu Git ou VCS). Ca sera beaucoup plus simple pour vous.

### SonarCloud

1. Connectez-vous avec votre compte GitHub. De cette façon, vos dépots seront automatiquement accessibles.
2. Lorsqu'on vous le demande, prenez l'offre gratuite (aka Open source).

### Travis CI

1. Connectez-vous avec votre compte GitHub. De cette façon, vos dépots seront automatiquement accessibles.
2. Liez votre compte Travis CI à votre compte GitHub (https://github.com/marketplace/travis-ci). Sélectionnez bien la version gratuite. Contactez Travis CI si vous avez des problèmes pour activer votre offre GitHub Student. Le support est très réactif.

**Vos comptes sont à présent configurés.**