package com.zeroone.star.sample.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：演示文件操作控制器
 * </p>
 *
 * @author Triple Gold
 * @version 1.0.0
 */
@Controller
@RequestMapping("file")
@Api(tags = "file")
public class FileController {
    @Resource
    FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;    // 服务器地址

    @PostMapping("upload-file")
    @ApiOperation(value = "文件上传")
    @ResponseBody
    public JsonVO<String> uploadFile(MultipartFile file) throws Exception {
        // 获取上传文件的后缀名
        String filename = file.getOriginalFilename();
        assert filename != null;
        String suffix = filename.substring(filename.lastIndexOf(".") + 1);
        // 上传文件
        FastDfsFileInfo result = dfs.uploadFile(file.getBytes(), suffix);
        if (result != null) {
            // 上传成功返回下载地址
            return JsonVO.success(dfs.fetchUrl(result, fileServerUrl, true));
        }
        return JsonVO.fail(null);
    }

    @GetMapping(value = "download-img", produces = "image/jpeg")
    @ApiOperation(value = "下载图片")
    public ResponseEntity<byte[]> downloadImage(String group, String id) throws Exception {
        // 下载文件
        byte[] fc = dfs.downloadFile(FastDfsFileInfo.builder().storageId(id).group(group).build());
        // 响应给前端
        HttpHeaders headers = new HttpHeaders();
        String fileName = "img-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".jpg";
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.IMAGE_JPEG);
        return new ResponseEntity<>(fc, headers, HttpStatus.CREATED);
    }

    @DeleteMapping("delete-file")
    @ApiOperation(value = "删除文件")
    @ResponseBody
    public JsonVO<Integer> deleteFile(String group, String id) throws Exception {
        int res = dfs.deleteFile(FastDfsFileInfo.builder().storageId(id).group(group).build());
        if (res == 0) {
            return JsonVO.success(0);
        }
        return JsonVO.fail(res);
    }
}
