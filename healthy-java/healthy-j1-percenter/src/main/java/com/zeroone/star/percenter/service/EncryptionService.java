package com.zeroone.star.percenter.service;

/**
 * 加密服务接口，用于密码加密和校验。
 */
public interface EncryptionService {

    /**
     * 加密给定的字符串（例如密码）。
     * @param input 需要加密的字符串。
     * @return 加密后的字符串。
     * @throws Exception 如果加密失败。
     */
    String encrypt(String input) throws Exception;
}