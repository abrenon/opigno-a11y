<?php

/**
 * quiz_codemirror.classes
 *
 * This module uses the question interface to define something which is actually not a question.
 *
 * A Quiz CodeMirror node is a placeholder for adding a CodeMirror page to a quiz. 
 * It will allow users to run some small code in the browser.
 *
 * @file
 */

/**
 * Extension of QuizQuestion.
 */
class QuizCodeMirrorQuestion extends QuizQuestion {

  /**
   * Constructor
   */
  public function __construct(stdClass $node) {
    parent::__construct($node);
    $this->node->no_skip_button = TRUE; // No skip button
    $this->node->not_a_question = TRUE;
  }

  /**
   * Implementation of validateNode
   *
   * @see QuizQuestion#validateNode($form)
   */
  public function validateNode(array &$form) { }

  /**
   * Implementation of saveNodeProperties
   *
   * @see QuizQuestion#saveNodeProperties($is_new)
   */
  public function saveNodeProperties($is_new = FALSE) { }

  /**
   * Implementation of getAnsweringForm
   *
   * @see QuizQuestion#getAnsweringForm($form_state, $rid)
   */
  public function getAnsweringForm(array $form_state = NULL, $rid) {
    $form = parent::getAnsweringForm($form_state, $rid);

    $form['tries'] = array(
      '#type' => 'hidden',
      '#value' => 0,
    );
    $form['empty_space'] = array(
      '#type' => 'markup',
      '#value' => '<br/>',
    );
    return $form;
  }

  /**
   * Implementation of getBodyFieldTitle
   *
   * @see QuizQuestion#getBodyFieldTitle()
   */
  public function getBodyFieldTitle() {
    return t('CodeMirror');
  }

  /**
   * Implementation of getCreationForm
   *
   * @see QuizQuestion#getCreationForm($form_state)
   */
  public function getCreationForm(array &$form_state = NULL) {
    return array();
  }

  /**
   * Implementation of getMaximumScore
   *
   * @see QuizQuestion#getMaximumScore()
   */
  public function getMaximumScore() {
    return 0;
  }
}

/**
 * Extension of QuizQuestionResponse
 */
class QuizCodeMirrorResponse extends QuizQuestionResponse {

  /**
   * Implementation of save
   *
   * @see QuizQuestionResponse#save()
   */
  public function save() { }

  /**
   * Implementation of delete
   *
   * @see QuizQuestionResponse#delete()
   */
  public function delete() { }

  /**
   * Implementation of score
   *
   * @see QuizQuestionResponse#score()
   */
  public function score() {
    // Set the score
    $this->score = 0;
    return 0;
  }

  /**
   * Implementation of isCorrect
   *
   * @see QuizQuestionResponse#isCorrect()
   */
  public function isCorrect() {
    return TRUE;
  }

  /**
   * Implementation of getResponse
   *
   * @see QuizQuestionResponse#getResponse()
   */
  public function getResponse() {
    return $this->answer;
  }

  /**
   * Implementation of getReportForm
   *
   * @see QuizQuestionResponse#getReportForm($showpoints, $showfeedback, $allow_scoring)
   */
  public function getReportForm($showpoints = TRUE, $showfeedback = TRUE, $allow_scoring = FALSE) {
    return array(
      '#no_report' => TRUE,
    );
  }
}




