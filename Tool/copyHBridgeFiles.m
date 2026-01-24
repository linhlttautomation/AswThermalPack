function copyHBridgeFiles()
    % Name of the project file
    projectName = 'HBridge.prj';

    % Search for the project file within the current project directory
    prjPath = dir(fullfile(pwd, '**', projectName));

    if isempty(prjPath)
        error('HBridge.prj not found in the project directory.');
    end

    % Get the directory where the project file is located
    projectRoot = prjPath(1).folder;

    % Define folders located at the same level as HBridge.prj
    workFolder = fullfile(projectRoot, 'work');
    dstFolder  = fullfile(projectRoot, 'HBridge_Code_Build');

    % Path to the generated code directory
    srcFolder = fullfile(workFolder, 'codegen', 'HBridge_ert_rtw');

    % Create output folder if it does not exist
    if ~exist(dstFolder, 'dir')
        mkdir(dstFolder);
    end

    % List of files to be copied
    files = { 'HBridge.c', 'HBridge.h', 'HBridge_types.h', 'rtwtypes.h', 'HBridge_internal.h' };

    % Copy each file
    for i = 1:length(files)
        src = fullfile(srcFolder, files{i});
        dst = fullfile(dstFolder, files{i});

        if exist(src, 'file')
            copyfile(src, dst);
            fprintf('Copied: %s\n', files{i});
        else
            fprintf('File not found: %s\n', files{i});
        end
    end
end
