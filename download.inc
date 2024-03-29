<?php
function r_case_study_proposal_literature_survey_file() {
	$proposal_id = arg(3);
	$root_path = r_case_study_path();
	$query = db_select('case_study_proposals_file');
	$query->fields('case_study_proposals_file');
	$query->condition('proposal_id', $proposal_id);
	$query->condition('filetype', 'S');
	$result = $query->execute();
	$case_study_literature_survey_files = $result->fetchObject();
	$query1 = db_select('case_study_proposal');
	$query1->fields('case_study_proposal');
	$query1->condition('id', $proposal_id);
	$result1 = $query1->execute();
	$case_study = $result1->fetchObject();
	$directory_name = $case_study->directory_name . '/';
	$literature_survey_file = $case_study_literature_survey_files->filename;
	ob_clean();
	header("Pragma: public");
	header("Expires: 0");
	header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
	header("Cache-Control: public");
	header("Content-Description: File Transfer");
	header("Content-Type:" . $case_study_abstract_file->filemime);
	header('Content-disposition: attachment; filename="' . $literature_survey_file . '"');
	header("Content-Length: " . filesize($root_path . $directory_name . $literature_survey_file));
	header("Content-Transfer-Encoding: binary");
	header("Expires: 0");
	header("Pragma: no-cache");
	readfile($root_path . $directory_name . $literature_survey_file);
	ob_end_flush();
	ob_clean();
}

function r_case_study_proposal_abstract_file() {
	$proposal_id = arg(3);
	$root_path = r_case_study_path();
	$query = db_select('case_study_proposals_file');
	$query->fields('case_study_proposals_file');
	$query->condition('proposal_id', $proposal_id);
	$query->condition('filetype', 'A');
	$result = $query->execute();
	$case_study_abstract_files = $result->fetchObject();
	$query1 = db_select('case_study_proposal');
	$query1->fields('case_study_proposal');
	$query1->condition('id', $proposal_id);
	$result1 = $query1->execute();
	$case_study = $result1->fetchObject();
	$directory_name = $case_study->directory_name . '/';
	$abstract_file = $case_study_abstract_files->filename;
	ob_clean();
	header("Pragma: public");
	header("Expires: 0");
	header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
	header("Cache-Control: public");
	header("Content-Description: File Transfer");
	header("Content-Type:" . $case_study_abstract_file->filemime);
	header('Content-disposition: attachment; filename="' . $abstract_file . '"');
	header("Content-Length: " . filesize($root_path . $directory_name . $abstract_file));
	header("Content-Transfer-Encoding: binary");
	header("Expires: 0");
	header("Pragma: no-cache");
	readfile($root_path . $directory_name . $abstract_file);
	ob_end_flush();
	ob_clean();
}

function r_case_study_proposal_rawdata_file() {
	$proposal_id = arg(3);
	$root_path = r_case_study_path();
	$query_file = db_select('case_study_proposals_file');
	$query_file->fields('case_study_proposals_file');
	$query_file->condition('proposal_id', $proposal_id);
	$query_file->condition('filetype', 'R');
	$result = $query_file->execute();
	$case_study_rawdata_files = $result->fetchObject();
	$query_pro = db_select('case_study_proposal');
	$query_pro->fields('case_study_proposal');
	$query_pro->condition('id', $proposal_id);
	$result_pro = $query_pro->execute();
	$case_study = $result_pro->fetchObject();
	$directory_name = $case_study->directory_name . '/';
	$rawdata_file = $case_study_rawdata_files->filename;
	//var_dump($directory_name);die;
	ob_clean();
	header("Pragma: public");
	header("Expires: 0");
	header("Cache-Control: must-revalidate, post-check=0, pre-check=0");
	header("Cache-Control: public");
	header("Content-Description: File Transfer");
	header("Content-Type: " . $case_study_rawdata_files->filemime);
	header('Content-disposition: attachment; filename="' . $rawdata_file . '"');
	header("Content-Length: " . filesize($root_path . $directory_name . $rawdata_file));
	header("Content-Transfer-Encoding: binary");
	header("Expires: 0");
	header("Pragma: no-cache");
	readfile($root_path . $directory_name . $rawdata_file);
		/*ob_end_flush();
		ob_clean();*/
}