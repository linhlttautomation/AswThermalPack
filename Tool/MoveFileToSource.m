function MoveFileToSource(srcDir)
    if nargin < 1 || isempty(rootDir)
        rootDir = pwd;
    end

    fprintf('[INFO] Collecting Thermal sources from:\n%s\n\n', rootDir);

    % ===============================
    % Configuration per model
    % ===============================
    models(1).name  = 'ThermalConv';
    models(2).name  = 'ThermalMon';
    models(3).name  = 'ThermalRct';

    for m = 1:numel(models)
        modelName = models(m).name;

        fprintf('=== Processing %s ===\n', modelName);

        % Destination
        dstDir = fullfile(rootDir, 'Source', modelName);
        if ~exist(dstDir, 'dir')
            mkdir(dstDir);
            fprintf('[INFO] Created folder: %s\n', dstDir);
        end

        % Preferred source locations
        searchPaths = {
            fullfile('slprj', 'ert', modelName)
            fullfile([modelName '_ert_rtw'])
            fullfile('slprj', 'ert', '_sharedutils')
        };

        % Required files
        files = {
            [modelName '.c']
            [modelName '.h']
            [modelName '_private.h']
            [modelName '_types.h']
            [modelName '_Internal.h']
            'complex_types.h'
        };

        copied = containers.Map;

        % Search and copy
        for p = 1:numel(searchPaths)
            srcDir = fullfile(rootDir, searchPaths{p});
            if ~exist(srcDir, 'dir')
                continue;
            end

            for f = 1:numel(files)
                fileName = files{f};

                % Avoid duplicate copy
                if isKey(copied, fileName)
                    continue;
                end

                srcFile = fullfile(srcDir, fileName);
                if exist(srcFile, 'file')
                    copyfile(srcFile, fullfile(dstDir, fileName), 'f');
                    copied(fileName) = true;
                    fprintf('[OK] %s ← %s\n', fileName, srcDir);
                end
            end
        end

        % Summary per model
        fprintf('[SUMMARY %s]\n', modelName);
        for f = 1:numel(files)
            if isKey(copied, files{f})
                fprintf('%s\n', files{f});
            else
                fprintf('%s (not found)\n', files{f});
            end
        end
        fprintf('\n');
    end

    modelNames = {models.name};
    fprintf('[SUCCESS] Sources collected successfully for models: %s\n', strjoin(modelNames, ', '));
end
